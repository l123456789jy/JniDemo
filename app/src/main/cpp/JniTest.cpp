//
// Created by uidq4442 on 2024-5-9 0009.
//


#include "JniTest.h"


std::string JniTest::getName() {
    std::string hello = "Hi C++ Jni test";
    return hello;
}

void JniTest::test_http_sync_client(HttpClient *cli) {
    HttpRequest req;
    req.method = HTTP_POST;
    req.url = "https://suggest.taobao.com/sug?code=utf-8&q=%E5%A5%B6%E7%93%B6&callback=cb";
    req.headers["Connection"] = "keep-alive";
    req.body = "This is a sync request.";
    req.timeout = 10;
    HttpResponse resp;
    int ret = cli->send(&req, &resp);
    if (ret != 0) {
        LOGE("request failed! %d",resp.status_code);
    } else {
        LOGE("%d %s", resp.status_code, resp.status_message());
        LOGE("%s", resp.body.c_str());
    }

}

