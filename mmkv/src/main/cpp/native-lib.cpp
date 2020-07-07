#include <jni.h>
#include <string>

extern "C" JNIEXPORT jstring JNICALL
Java_com_hxjb_olymic_1mmkv_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}


extern "C"
JNIEXPORT void JNICALL
Java_com_hxjb_mmkv_MMKV_jniInitialize(JNIEnv *env, jclass clazz, jstring root_dir, jint level) {
    // TODO: implement jniInitialize()
}