#pragma once
#include "CoreMinimal.h"

UENUM(BlueprintType)
namespace ESetDOType {
	enum Type{
		OAxis,
		OAction
	};
}

UENUM(BlueprintType)
namespace EIOEvent {
	enum Type {
		IE_Pressed = 0,
		IE_Released = 1,
		IE_Repeat = 2,
		IE_DoubleClick = 3,
		IE_Axis = 4,
		IE_MAX = 5,
	};
}

UENUM(BlueprintType)
enum EIO_Key
{
    AnyKey = 0,

    Button_00,
    Button_01,
    Button_02,
    Button_03,
    Button_04,
    Button_05,
    Button_06,
    Button_07,
    Button_08,
    Button_09,
    Button_10,
    Button_11,
    Button_12,
    Button_13,
    Button_14,
    Button_15,
    Button_16,
    Button_17,
    Button_18,
    Button_19,
    Button_20,
    Button_21,
    Button_22,
    Button_23,
    Button_24,
    Button_25,
    Button_26,
    Button_27,
    Button_28,
    Button_29,
    Button_30,
    Button_31,

    Axis_00,
    Axis_01,
    Axis_02,
    Axis_03,
    Axis_04,
    Axis_05,
    Axis_06,
    Axis_07,
    Axis_08,
    Axis_09,
    Axis_10,
    Axis_11,
    Axis_12,
    Axis_13,
    Axis_14,
    Axis_15,
    Axis_16,
    Axis_17,
    Axis_18,
    Axis_19,
    Axis_20,
    Axis_21,
    Axis_22,
    Axis_23,
    Axis_24,
    Axis_25,
    Axis_26,
    Axis_27,
    Axis_28,
    Axis_29,
    Axis_30,
    Axis_31,

    Zero,
    One,
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,

    A,
    B,
    C,
    D,
    E,
    F,
    G,
    H,
    I,
    J,
    K,
    L,
    M,
    N,
    O,
    P,
    Q,
    R,
    S,
    T,
    U,
    V,
    W,
    X,
    Y,
    Z,

    NumPadZero,
    NumPadOne,
    NumPadTwo,
    NumPadThree,
    NumPadFour,
    NumPadFive,
    NumPadSix,
    NumPadSeven,
    NumPadEight,
    NumPadNine,

    Multiply,
    Add,
    Subtract,
    Decimal,
    Divide,

    F1,
    F2,
    F3,
    F4,
    F5,
    F6,
    F7,
    F8,
    F9,
    F10,
    F11,
    F12,

    Left,
    Up,
    Right,
    Down,

    MouseX,
    MouseY,
    MouseScrollUp,
    MouseScrollDown,
    MouseWheelAxis,

    LeftMouseButton,
    RightMouseButton,
    MiddleMouseButton,
    ThumbMouseButton,
    ThumbMouseButton2,

    BackSpace,
    Tab,
    Enter,
    Pause,

    CapsLock,
    Escape,
    SpaceBar,
    PageUp,
    PageDown,
    End,
    Home,

    Insert,
    Delete,

    NumLock,
    ScrollLock,

    LeftShift,
    RightShift,
    LeftControl,
    RightControl,
    LeftAlt,
    RightAlt,
    LeftCommand,
    RightCommand,
    Invalid,

    JS_X,
    JS_Y,
    JS_Z,
    JS_Rx,
    JS_Ry,
    JS_Rz,
    JS_VX,
    JS_VY,
    JS_VZ,
    JS_VRx,
    JS_VRy,
    JS_VRz,
    JS_AX,
    JS_AY,
    JS_AZ,
    JS_ARx,
    JS_ARy,
    JS_ARz,
    JS_FX,
    JS_FY,
    JS_FZ,
    JS_FRx,
    JS_FRy,
    JS_FRz,

    JS_Slider_00,
    JS_Slider_01,

    JS_VSlider_00,
    JS_VSlider_01,

    JS_ASlider_00,
    JS_ASlider_01,

    JS_FSlider_00,
    JS_FSlider_01,

    JS_POV_00,
    JS_POV_01,
    JS_POV_02,
    JS_POV_03
};

UENUM(BlueprintType)
namespace EIO_ButtonKey 
{
    enum Type {
        Button_00 = 0,
        Button_01,
        Button_02,
        Button_03,
        Button_04,
        Button_05,
        Button_06,
        Button_07,
        Button_08,
        Button_09,
        Button_10,
        Button_11,
        Button_12,
        Button_13,
        Button_14,
        Button_15,
        Button_16,
        Button_17,
        Button_18,
        Button_19,
        Button_20,
        Button_21,
        Button_22,
        Button_23,
        Button_24,
        Button_25,
        Button_26,
        Button_27,
        Button_28,
        Button_29,
        Button_30,
        Button_31,
        Button_32,
        Button_33,
        Button_34,
        Button_35,
        Button_36,
        Button_37,
        Button_38,
        Button_39,
        Button_40,
        Button_41,
        Button_42,
        Button_43,
        Button_44,
        Button_45,
        Button_46,
        Button_47,
        Button_48,
        Button_49,
        Button_50,
        Button_51,
        Button_52,
        Button_53,
        Button_54,
        Button_55,
        Button_56,
        Button_57,
        Button_58,
        Button_59,
        Button_60,
        Button_61,
        Button_62,
        Button_63,
        Button_64,
        Button_65,
        Button_66,
        Button_67,
        Button_68,
        Button_69,
        Button_70,
        Button_71,
        Button_72,
        Button_73,
        Button_74,
        Button_75,
        Button_76,
        Button_77,
        Button_78,
        Button_79,
        Button_80,
        Button_81,
        Button_82,
        Button_83,
        Button_84,
        Button_85,
        Button_86,
        Button_87,
        Button_88,
        Button_89,
        Button_90,
        Button_91,
        Button_92,
        Button_93,
        Button_94,
        Button_95,
        Button_96,
        Button_97,
        Button_98,
        Button_99,
        Button_100,
        Button_101,
        Button_102,
        Button_103,
        Button_104,
        Button_105,
        Button_106,
        Button_107,
        Button_108,
        Button_109,
        Button_110,
        Button_111,
        Button_112,
        Button_113,
        Button_114,
        Button_115,
        Button_116,
        Button_117,
        Button_118,
        Button_119,
        Button_120,
        Button_121,
        Button_122,
        Button_123,
        Button_124,
        Button_125,
        Button_126,
        Button_127,
        Button_128,
        Button_129,
        Button_130,
        Button_131,
        Button_132,
        Button_133,
        Button_134,
        Button_135,
        Button_136,
        Button_137,
        Button_138,
        Button_139,
        Button_140,
        Button_141,
        Button_142,
        Button_143,
        Button_144,
        Button_145,
        Button_146,
        Button_147,
        Button_148,
        Button_149,
        Button_150,
        Button_151,
        Button_152,
        Button_153,
        Button_154,
        Button_155,
        Button_156,
        Button_157,
        Button_158,
        Button_159,
        Button_160,
        Button_161,
        Button_162,
        Button_163,
        Button_164,
        Button_165,
        Button_166,
        Button_167,
        Button_168,
        Button_169,
        Button_170,
        Button_171,
        Button_172,
        Button_173,
        Button_174,
        Button_175,
        Button_176,
        Button_177,
        Button_178,
        Button_179,
        Button_180,
        Button_181,
        Button_182,
        Button_183,
        Button_184,
        Button_185,
        Button_186,
        Button_187,
        Button_188,
        Button_189,
        Button_190,
        Button_191,
        Button_192,
        Button_193,
        Button_194,
        Button_195,
        Button_196,
        Button_197,
        Button_198,
        Button_199,
        Button_200,
        Button_201,
        Button_202,
        Button_203,
        Button_204,
        Button_205,
        Button_206,
        Button_207,
        Button_208,
        Button_209,
        Button_210,
        Button_211,
        Button_212,
        Button_213,
        Button_214,
        Button_215,
        Button_216,
        Button_217,
        Button_218,
        Button_219,
        Button_220,
        Button_221,
        Button_222,
        Button_223,
        Button_224,
        Button_225,
        Button_226,
        Button_227,
        Button_228,
        Button_229,
        Button_230,
        Button_231,
        Button_232,
        Button_233,
        Button_234,
        Button_235,
        Button_236,
        Button_237,
        Button_238,
        Button_239,
        Button_240,
        Button_241,
        Button_242,
        Button_243,
        Button_244,
        Button_245,
        Button_246,
        Button_247,
        Button_248,
        Button_249,
        Button_250,
        Button_251,
        Button_252,
        Button_253,
        Button_254,
        Button_255
    };
}

UENUM(BlueprintType)
namespace EIO_AxisKey 
{
    enum Type
    {
        Axis_00 = 0,
        Axis_01,
        Axis_02,
        Axis_03,
        Axis_04,
        Axis_05,
        Axis_06,
        Axis_07,
        Axis_08,
        Axis_09,
        Axis_10,
        Axis_11,
        Axis_12,
        Axis_13,
        Axis_14,
        Axis_15,
        Axis_16,
        Axis_17,
        Axis_18,
        Axis_19,
        Axis_20,
        Axis_21,
        Axis_22,
        Axis_23,
        Axis_24,
        Axis_25,
        Axis_26,
        Axis_27,
        Axis_28,
        Axis_29,
        Axis_30,
        Axis_31,
        Axis_32,
        Axis_33,
        Axis_34,
        Axis_35,
        Axis_36,
        Axis_37,
        Axis_38,
        Axis_39,
        Axis_40,
        Axis_41,
        Axis_42,
        Axis_43,
        Axis_44,
        Axis_45,
        Axis_46,
        Axis_47,
        Axis_48,
        Axis_49,
        Axis_50,
        Axis_51,
        Axis_52,
        Axis_53,
        Axis_54,
        Axis_55,
        Axis_56,
        Axis_57,
        Axis_58,
        Axis_59,
        Axis_60,
        Axis_61,
        Axis_62,
        Axis_63,
        Axis_64,
        Axis_65,
        Axis_66,
        Axis_67,
        Axis_68,
        Axis_69,
        Axis_70,
        Axis_71,
        Axis_72,
        Axis_73,
        Axis_74,
        Axis_75,
        Axis_76,
        Axis_77,
        Axis_78,
        Axis_79,
        Axis_80,
        Axis_81,
        Axis_82,
        Axis_83,
        Axis_84,
        Axis_85,
        Axis_86,
        Axis_87,
        Axis_88,
        Axis_89,
        Axis_90,
        Axis_91,
        Axis_92,
        Axis_93,
        Axis_94,
        Axis_95,
        Axis_96,
        Axis_97,
        Axis_98,
        Axis_99,
        Axis_100,
        Axis_101,
        Axis_102,
        Axis_103,
        Axis_104,
        Axis_105,
        Axis_106,
        Axis_107,
        Axis_108,
        Axis_109,
        Axis_110,
        Axis_111,
        Axis_112,
        Axis_113,
        Axis_114,
        Axis_115,
        Axis_116,
        Axis_117,
        Axis_118,
        Axis_119,
        Axis_120,
        Axis_121,
        Axis_122,
        Axis_123,
        Axis_124,
        Axis_125,
        Axis_126,
        Axis_127,
        Axis_128,
        Axis_129,
        Axis_130,
        Axis_131,
        Axis_132,
        Axis_133,
        Axis_134,
        Axis_135,
        Axis_136,
        Axis_137,
        Axis_138,
        Axis_139,
        Axis_140,
        Axis_141,
        Axis_142,
        Axis_143,
        Axis_144,
        Axis_145,
        Axis_146,
        Axis_147,
        Axis_148,
        Axis_149,
        Axis_150,
        Axis_151,
        Axis_152,
        Axis_153,
        Axis_154,
        Axis_155,
        Axis_156,
        Axis_157,
        Axis_158,
        Axis_159,
        Axis_160,
        Axis_161,
        Axis_162,
        Axis_163,
        Axis_164,
        Axis_165,
        Axis_166,
        Axis_167,
        Axis_168,
        Axis_169,
        Axis_170,
        Axis_171,
        Axis_172,
        Axis_173,
        Axis_174,
        Axis_175,
        Axis_176,
        Axis_177,
        Axis_178,
        Axis_179,
        Axis_180,
        Axis_181,
        Axis_182,
        Axis_183,
        Axis_184,
        Axis_185,
        Axis_186,
        Axis_187,
        Axis_188,
        Axis_189,
        Axis_190,
        Axis_191,
        Axis_192,
        Axis_193,
        Axis_194,
        Axis_195,
        Axis_196,
        Axis_197,
        Axis_198,
        Axis_199,
        Axis_200,
        Axis_201,
        Axis_202,
        Axis_203,
        Axis_204,
        Axis_205,
        Axis_206,
        Axis_207,
        Axis_208,
        Axis_209,
        Axis_210,
        Axis_211,
        Axis_212,
        Axis_213,
        Axis_214,
        Axis_215,
        Axis_216,
        Axis_217,
        Axis_218,
        Axis_219,
        Axis_220,
        Axis_221,
        Axis_222,
        Axis_223,
        Axis_224,
        Axis_225,
        Axis_226,
        Axis_227,
        Axis_228,
        Axis_229,
        Axis_230,
        Axis_231,
        Axis_232,
        Axis_233,
        Axis_234,
        Axis_235,
        Axis_236,
        Axis_237,
        Axis_238,
        Axis_239,
        Axis_240,
        Axis_241,
        Axis_242,
        Axis_243,
        Axis_244,
        Axis_245,
        Axis_246,
        Axis_247,
        Axis_248,
        Axis_249,
        Axis_250,
        Axis_251,
        Axis_252,
        Axis_253,
        Axis_254,
        Axis_255
    };
}


UENUM(BlueprintType)
enum EIO_OAxisKey
{
    OAxis_00 = 0,
    OAxis_01,
    OAxis_02,
    OAxis_03,
    OAxis_04,
    OAxis_05,
    OAxis_06,
    OAxis_07,
    OAxis_08,
    OAxis_09,
    OAxis_10,
    OAxis_11,
    OAxis_12,
    OAxis_13,
    OAxis_14,
    OAxis_15,
    OAxis_16,
    OAxis_17,
    OAxis_18,
    OAxis_19,
    OAxis_20,
    OAxis_21,
    OAxis_22,
    OAxis_23,
    OAxis_24,
    OAxis_25,
    OAxis_26,
    OAxis_27,
    OAxis_28,
    OAxis_29,
    OAxis_30,
    OAxis_31,
    OAxis_32,
    OAxis_33,
    OAxis_34,
    OAxis_35,
    OAxis_36,
    OAxis_37,
    OAxis_38,
    OAxis_39,
    OAxis_40,
    OAxis_41,
    OAxis_42,
    OAxis_43,
    OAxis_44,
    OAxis_45,
    OAxis_46,
    OAxis_47,
    OAxis_48,
    OAxis_49,
    OAxis_50,
    OAxis_51,
    OAxis_52,
    OAxis_53,
    OAxis_54,
    OAxis_55,
    OAxis_56,
    OAxis_57,
    OAxis_58,
    OAxis_59,
    OAxis_60,
    OAxis_61,
    OAxis_62,
    OAxis_63,
    OAxis_64,
    OAxis_65,
    OAxis_66,
    OAxis_67,
    OAxis_68,
    OAxis_69,
    OAxis_70,
    OAxis_71,
    OAxis_72,
    OAxis_73,
    OAxis_74,
    OAxis_75,
    OAxis_76,
    OAxis_77,
    OAxis_78,
    OAxis_79,
    OAxis_80,
    OAxis_81,
    OAxis_82,
    OAxis_83,
    OAxis_84,
    OAxis_85,
    OAxis_86,
    OAxis_87,
    OAxis_88,
    OAxis_89,
    OAxis_90,
    OAxis_91,
    OAxis_92,
    OAxis_93,
    OAxis_94,
    OAxis_95,
    OAxis_96,
    OAxis_97,
    OAxis_98,
    OAxis_99,
    OAxis_100,
    OAxis_101,
    OAxis_102,
    OAxis_103,
    OAxis_104,
    OAxis_105,
    OAxis_106,
    OAxis_107,
    OAxis_108,
    OAxis_109,
    OAxis_110,
    OAxis_111,
    OAxis_112,
    OAxis_113,
    OAxis_114,
    OAxis_115,
    OAxis_116,
    OAxis_117,
    OAxis_118,
    OAxis_119,
    OAxis_120,
    OAxis_121,
    OAxis_122,
    OAxis_123,
    OAxis_124,
    OAxis_125,
    OAxis_126,
    OAxis_127,
    OAxis_128,
    OAxis_129,
    OAxis_130,
    OAxis_131,
    OAxis_132,
    OAxis_133,
    OAxis_134,
    OAxis_135,
    OAxis_136,
    OAxis_137,
    OAxis_138,
    OAxis_139,
    OAxis_140,
    OAxis_141,
    OAxis_142,
    OAxis_143,
    OAxis_144,
    OAxis_145,
    OAxis_146,
    OAxis_147,
    OAxis_148,
    OAxis_149,
    OAxis_150,
    OAxis_151,
    OAxis_152,
    OAxis_153,
    OAxis_154,
    OAxis_155,
    OAxis_156,
    OAxis_157,
    OAxis_158,
    OAxis_159,
    OAxis_160,
    OAxis_161,
    OAxis_162,
    OAxis_163,
    OAxis_164,
    OAxis_165,
    OAxis_166,
    OAxis_167,
    OAxis_168,
    OAxis_169,
    OAxis_170,
    OAxis_171,
    OAxis_172,
    OAxis_173,
    OAxis_174,
    OAxis_175,
    OAxis_176,
    OAxis_177,
    OAxis_178,
    OAxis_179,
    OAxis_180,
    OAxis_181,
    OAxis_182,
    OAxis_183,
    OAxis_184,
    OAxis_185,
    OAxis_186,
    OAxis_187,
    OAxis_188,
    OAxis_189,
    OAxis_190,
    OAxis_191,
    OAxis_192,
    OAxis_193,
    OAxis_194,
    OAxis_195,
    OAxis_196,
    OAxis_197,
    OAxis_198,
    OAxis_199,
    OAxis_200,
    OAxis_201,
    OAxis_202,
    OAxis_203,
    OAxis_204,
    OAxis_205,
    OAxis_206,
    OAxis_207,
    OAxis_208,
    OAxis_209,
    OAxis_210,
    OAxis_211,
    OAxis_212,
    OAxis_213,
    OAxis_214,
    OAxis_215,
    OAxis_216,
    OAxis_217,
    OAxis_218,
    OAxis_219,
    OAxis_220,
    OAxis_221,
    OAxis_222,
    OAxis_223,
    OAxis_224,
    OAxis_225,
    OAxis_226,
    OAxis_227,
    OAxis_228,
    OAxis_229,
    OAxis_230,
    OAxis_231,
    OAxis_232,
    OAxis_233,
    OAxis_234,
    OAxis_235,
    OAxis_236,
    OAxis_237,
    OAxis_238,
    OAxis_239,
    OAxis_240,
    OAxis_241,
    OAxis_242,
    OAxis_243,
    OAxis_244,
    OAxis_245,
    OAxis_246,
    OAxis_247,
    OAxis_248,
    OAxis_249,
    OAxis_250,
    OAxis_251,
    OAxis_252,
    OAxis_253,
    OAxis_254,
    OAxis_255,
};
