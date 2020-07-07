package com.hxjb.mmkv;

import android.content.Context;

/**
 * create by aliouswang
 */
public class MMKV {

    static String rootDir = null;

    public static String getRootDir() {
        return rootDir;
    }

    public static String initialize(Context context) {
        String rootDir = context.getFilesDir().getAbsolutePath() + "/mmkv";
        MMKVLogLevel logLevel = BuildConfig.DEBUG ? MMKVLogLevel.LevelDebug : MMKVLogLevel.LevelInfo;
        return initialize(rootDir, logLevel);
    }

    public static String initialize(String rootDir, MMKVLogLevel logLevel) {
        MMKV.rootDir = rootDir;
        System.loadLibrary("mmkv");
        return rootDir;
    }


    private long nativeHandle;
    private static native void jniInitialize(String rootDir, int level);

}
