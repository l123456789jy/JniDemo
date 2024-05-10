
#include <string>
#include "include/hv/requests.h"
#include "include/hv/axios.h"
using namespace hv;

#include "include/hv/hthread.h" // import hv_gettid
#include "include/hv/HttpClient.h"
#include "include/hv/requests.h"
#include <iostream>
#include <memory>
#include <android/log.h>

#define TAG        "Leoric"
#define LOGI(...)    __android_log_print(ANDROID_LOG_INFO, TAG, __VA_ARGS__)
#define LOGD(...)    __android_log_print(ANDROID_LOG_DEBUG, TAG, __VA_ARGS__)
#define LOGW(...)    __android_log_print(ANDROID_LOG_WARN, TAG, __VA_ARGS__)
#define    LOGE(...)    __android_log_print(ANDROID_LOG_ERROR, TAG, __VA_ARGS__)


#ifndef JNIDEMO_JNITEST_H
#define JNIDEMO_JNITEST_H

#endif //JNIDEMO_JNITEST_H
class JniTest{

public:
    std::string getName();
    void test_http_sync_client(HttpClient* cli);
};