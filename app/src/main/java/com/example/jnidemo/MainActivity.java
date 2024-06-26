package com.example.jnidemo;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.util.Log;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        // Example of a call to a native method
         TextView tv = findViewById(R.id.sample_text);
         tv.setText(callHai());
         callJavaMether();
        Persion persion = new Persion();
        startHttpRequest(persion);
        int speed = getLocation().speed;
        Log.e("MainActivity", "speed: "+speed);
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native void callJavaMether();
    public native String callHai();
    public native void startHttpRequest(Persion persion);

    public native Location getLocation();

}