//
// Created by mac on 2020/7/7.
//

#include <jni.h>
#include <string>
#include <cstdint>
#include "MMKVLog.h"
#include "ALog.cpp"

using namespace std;

static JavaVM *g_currentJVM = nullptr;
static jclass g_cls = nullptr;
static jfieldID g_fieldId = nullptr;

static int registerNativeMethods(JNIEnv *env, jclass cls);

extern "C" JNIEXPORT JNICALL jint JNI_OnLoad(JavaVM *vm, void *reserved) {
    g_currentJVM = vm;
    JNIEnv *env;
    if (vm->GetEnv(reinterpret_cast<void **> (&env), JNI_VERSION_1_6) != JNI_OK) {
        return -1;
    }
    if (g_cls) {
        env->DeleteGlobalRef(g_cls);
    }
    static const char *clsName = "com/hxjb/mmkv/MMKV";
    jclass instance = env->FindClass(clsName);
    if (!instance) {
        LOGE("fail to locate class: %s", clsName);
        return -2;
    }
    g_cls = reinterpret_cast<jclass>(env->NewGlobalRef(instance));
    if (!g_cls) {
        LOGE("fail to create global reference for %s", clsName);
        return -3;
    }
    int ret = registerNativeMethods(env, g_cls);
    if (ret != 0) {
        LOGE("fail to register native methods for class %s, ret = %d", clsName, ret);
        return -4;
    }
    g_fieldId = env->GetFieldID(g_cls, "nativeHandle", "J");
    if (!g_fieldId) {
        LOGE("faild to locate fileID");
        return -5;
    }
    return JNI_VERSION_1_6;
}



static JNINativeMethod g_methods[] = {
        {"jniInitialize", "(Ljava/lang/String;I)V", }
};

static int registerNativeMethods(JNIEnv *env, jclass cls) {

}





























