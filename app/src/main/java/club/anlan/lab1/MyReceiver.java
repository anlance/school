package club.anlan.lab1;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.util.Log;
import android.widget.TextView;
import android.widget.Toast;

public class MyReceiver extends BroadcastReceiver {
    private MsgCallBack msgCallBack;

    @Override
    public void onReceive(Context context, Intent intent) {
        msgCallBack.setRankInfo(intent.getStringExtra("usedTime"),intent.getStringExtra("userName"));
        Log.i("---0000----", "onReceive: "+intent.getStringExtra("usedTime"));
        Log.i("---0000----", "onReceive: "+intent.getStringExtra("userName"));
    }

    public interface MsgCallBack{
        public void setRankInfo(String usedTime, String userName);
    }

    public void setMsgCallBack(MsgCallBack msgCallBack) {
        this.msgCallBack = msgCallBack;
    }
}
