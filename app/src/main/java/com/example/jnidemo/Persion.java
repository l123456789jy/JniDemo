package com.example.jnidemo;

import android.util.Log;

public class Persion {
    // 等待C++调用
    public void setAge(int age){
        Log.e("Persion", "setAge: "+age);
    }

    public  void notifyCallback(Object msg){
        Log.e("Persion", "notifyCallback: "+msg.toString());

    }


}
