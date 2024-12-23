﻿// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

using System;
using System.IO;
using System.Reflection;
using UnrealBuildTool;
public class IOToolkit : ModuleRules {
    private string projectDir {
        get {
            return Path.Combine (ModuleDirectory, "../../../../");
        }
    }

    private string pluginDir {
        get {
            return Path.Combine (ModuleDirectory, "../../");
        }
    }
#if UE_4_17_OR_LATER
    public IOToolkit (ReadOnlyTargetRules Target) : base (Target)
#else
    public IOToolkit (TargetInfo Target)
#endif
    {
        // uncomment code below to package project without rebuild this module
        //bUsePrecompiled = true;
        //PrecompileForTargets = PrecompileTargetsType.None;

        PublicIncludePaths.AddRange (
            new string[] {
                Path.Combine (pluginDir, "Source/IOToolkit/Public"),
                Path.Combine (pluginDir, "ThirdParty")
                // ... add public include paths required here ...
            }
        );

        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        string _ioModuleDir = Path.Combine (pluginDir, "ThirdParty/IOToolkit");
        if (!Directory.Exists (_ioModuleDir)) {
            Console.WriteLine ("[Error]: Can not find IOToolkit module which should be located at: " +
                Path.GetFullPath (_ioModuleDir));
        }

#if UE_5_0_OR_LATER
        string _platform = Target.Platform.ToString (); //== UnrealTargetPlatform.Win32 ? "Win32" : "Win64";
#else
        string _platform = Target.Platform == UnrealTargetPlatform.Win32 ? "Win32" : "Win64";
#endif

        CopyAll (
            new DirectoryInfo (Path.Combine (pluginDir, "ThirdParty/IOToolkit/binaries", _platform)),
            new DirectoryInfo (Path.Combine (pluginDir, "Binaries", _platform))
        );
        PrivateIncludePaths.AddRange (
            new string[] {
                "IOToolkit/Private",
                // ... add other private include paths required here ...
            }
        );

        PublicDependencyModuleNames.AddRange (
            new string[] {
                "Core",
                "Projects"
                // ... add other public dependencies that you statically link with here ...
            }
        );

        PublicAdditionalLibraries.Add (Path.Combine (pluginDir, "Binaries", _platform, "IODevice.lib"));

        // Delay-load the DLL, so we can load it from the right place first
        PublicDelayLoadDLLs.Add ("IODevice.dll");
        PrivateDependencyModuleNames.AddRange (
            new string[] {
                "CoreUObject",
                "Engine",
                "Slate",
                "SlateCore",
                "Networking"
                // ... add private dependencies that you statically link with here ...	
            }
        );

        DynamicallyLoadedModuleNames.AddRange (
            new string[] {
                // ... add any modules that your module loads dynamically here ...
            }
        );

        RuntimeDependencies.Add (Path.Combine ("$(PluginDir)/Binaries", _platform, "..."), StagedFileType.NonUFS);
    }

    private static void CopyAll (DirectoryInfo source, DirectoryInfo target) {
        if (!Directory.Exists (source.FullName)) {
            return;
        }

        if (!Directory.Exists (target.FullName)) {
            Directory.CreateDirectory (target.FullName);
        }

        foreach (var fileInfo in source.GetFiles ()) {
            var _targetPath = Path.Combine (target.ToString (), fileInfo.Name);
            if (File.Exists (_targetPath)) continue;
            fileInfo.CopyTo (_targetPath, true);
        }

        foreach (var subDirInfo in source.GetDirectories ()) {
            if (subDirInfo.Name == "Logs") continue;
            DirectoryInfo nextTargetSubDir = target.CreateSubdirectory (subDirInfo.Name);
            CopyAll (subDirInfo, nextTargetSubDir);
        }
    }
}