package club.anlan.second;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.util.Log;

public class MyReceiver extends BroadcastReceiver {
    @Override
    public void onReceive(Context context, Intent intent) {
        String actions = intent.getAction();
        String msg = intent.getStringExtra("msg");
        Log.i("hello", "onReceive: "+msg);
    }
}
