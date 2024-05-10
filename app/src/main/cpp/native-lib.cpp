#include <jni.h>
#include <string>
#include <android/log.h>
#include "JniTest.h"
#include "include/hv/HttpClient.h"

using namespace hv;

#define TAG        "Leoric"
#define LOGI(...)    __android_log_print(ANDROID_LOG_INFO, TAG, __VA_ARGS__)
#define LOGD(...)    __android_log_print(ANDROID_LOG_DEBUG, TAG, __VA_ARGS__)
#define LOGW(...)    __android_log_print(ANDROID_LOG_WARN, TAG, __VA_ARGS__)
#define    LOGE(...)    __android_log_print(ANDROID_LOG_ERROR, TAG, __VA_ARGS__)


extern "C" {

// java 调用C++
JNIEXPORT jstring JNICALL Java_com_example_jnidemo_MainActivity_callHai(
        JNIEnv *env,
        jobject /* this */) {
    JniTest jniTest;
    LOGE("Java_com_example_jnidemo_MainActivity_callHai...");
    return env->NewStringUTF(jniTest.getName().c_str());
}

// C++ 调用java 方法
JNIEXPORT void JNICALL
Java_com_example_jnidemo_MainActivity_callJavaMether(JNIEnv *env, jobject /* this */) {
    // 获取需要调用类的全路径
    jclass classId = env->FindClass("com/example/jnidemo/Persion");
    if (!classId) {
        LOGE("Java_com_example_jnidemo_MainActivity_callJavaMether...FindClass NULL");
        return;
    }
    // 获取方法ID
    jmethodID setAgeMethodId = env->GetMethodID(classId, "setAge", "(I)V");
    //调用构造
    jmethodID constructorId = env->GetMethodID(classId, "<init>", "()V");
    // setAge 方法不是静态方法，则需要创建 Persion 对象的实例
    jobject persionObject = env->NewObject(classId, constructorId);
    if (persionObject == nullptr) {
        LOGE("Java_com_example_jnidemo_MainActivity_callJavaMether...persionObject NULL");
    }
    //调用setAge方法
    int age = 25; // 设置年龄值
    env->CallVoidMethod(persionObject, setAgeMethodId, age);
}

};



extern "C"
JNIEXPORT void JNICALL
Java_com_example_jnidemo_MainActivity_startHttpRequest(JNIEnv *env, jobject thiz) {
    HttpClient sync_client;
    JniTest jniTest;
    jniTest.test_http_sync_client(&sync_client);
}