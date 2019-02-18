package club.anlan.lab1;


import android.content.Context;
import android.content.IntentFilter;
import android.content.SharedPreferences;
import android.media.MediaPlayer;
import android.os.Bundle;
import android.support.v4.app.FragmentManager;
import android.support.v4.app.FragmentTransaction;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;
import android.view.View;
import android.widget.FrameLayout;
import android.widget.TextView;


public class MainActivity extends AppCompatActivity implements View.OnClickListener{

    //UI Object
    private TextView txt_topbar;
    private TextView txt_game;
    private TextView txt_rank;
    private TextView txt_info;
    private FrameLayout ly_content;
    private int level;

    private FragmentManager fManager;
    private BgMusicThread bmt;
    private MyApplication myApplication;

    private static MediaPlayer bgMusic;
    private SharedPreferences sp;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        sp = getSharedPreferences("config", Context.MODE_PRIVATE);
        fManager = getSupportFragmentManager();
        bindViews();
        myApplication = (MyApplication) MyApplication.getInstance();
        // 注册广播接收器
        FragmentTransaction fTransaction = fManager.beginTransaction();
        if(myApplication.getFgRank()==null){
            RankFragment fgRank = new RankFragment();
            fTransaction.add(R.id.ly_content,fgRank);
            fTransaction.commit();
            myApplication.setFgRank(fgRank);
        }
        IntentFilter intentFilter = new IntentFilter();
        intentFilter.addAction("updateRank");
        MyReceiver myReceiver = new MyReceiver();
        registerReceiver(myReceiver,intentFilter);
        myReceiver.setMsgCallBack(myApplication.getFgRank());

        txt_game.performClick();   //模拟一次点击，既进去后选择第一
    }

    //UI组件初始化与事件绑定
    private void bindViews() {
        txt_game = (TextView) findViewById(R.id.txt_game);
        txt_rank = (TextView) findViewById(R.id.txt_rank);
        txt_info = (TextView) findViewById(R.id.txt_info);
        ly_content = (FrameLayout) findViewById(R.id.ly_content);

        txt_game.setOnClickListener(this);
        txt_rank.setOnClickListener(this);
        txt_info.setOnClickListener(this);
    }

    //重置所有文本的选中状态
    private void setSelected(){
        txt_game.setSelected(false);
        txt_rank.setSelected(false);
        txt_info.setSelected(false);
    }


    @Override
    public void onClick(View v) {
        FragmentTransaction fTransaction = fManager.beginTransaction();
        myApplication.hideAllFragment(fTransaction);
        switch (v.getId()){
            case R.id.txt_game:
                setSelected();
                txt_game.setSelected(true);
                if(myApplication.getFgGame() == null){
                    GameFragment fgGame = new GameFragment();
                    myApplication.setFgGame(fgGame);//修改全局变量
                    fTransaction.add(R.id.ly_content,fgGame);
                }else if(myApplication!=null && myApplication.getLevle()!=level){
                    fTransaction.remove(myApplication.getFgGame());
                    level = myApplication.getLevle();
                    GameFragment fgGame = new GameFragment();
                    myApplication.setFgGame(fgGame);
                    fTransaction.add(R.id.ly_content,fgGame);
                }
                else{
                    fTransaction.show(myApplication.getFgGame());
                }
                if(sp.getBoolean("swhBgMusic",false)){
                    bmt = new BgMusicThread();
                    bmt.start();
                }
                break;
            case R.id.txt_rank:
                setSelected();
                txt_rank.setSelected(true);
                if(myApplication.getFgRank() == null){
                    RankFragment fgRank = new RankFragment();
                    myApplication.setFgRank(fgRank);
                    fTransaction.add(R.id.ly_content,fgRank);
                }else{
                    fTransaction.show(myApplication.getFgRank());
                }
                if(bgMusic!=null){
                    stopMusic();
                }
                break;
            case R.id.txt_info:
                setSelected();
                txt_info.setSelected(true);
                if(myApplication.getFgInfo() == null){
                    InfoFragment fgInfo = new InfoFragment();
                    myApplication.setFgInfo(fgInfo);
                    fTransaction.add(R.id.ly_content,fgInfo);
                }else{
                    fTransaction.show(myApplication.getFgInfo());
                }
                if(bgMusic!=null){
                    stopMusic();
                }
                break;
        }
        fTransaction.commit();
    }


    //---  背景音乐 ---//
    public class BgMusicThread extends Thread {
        private boolean isAlive;

        @Override
        public void run() {
            if(bgMusic==null){
                bgMusic = MediaPlayer.create(MainActivity.this, R.raw.bg_music);
            }
            bgMusic.setLooping(true);
            bgMusic.start();
        }

    }


    public void stopMusic(){
        bgMusic.setLooping(false);
        bgMusic.stop();
        bgMusic.reset();
        bgMusic.release();
        bgMusic = null;
    }

}