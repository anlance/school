package club.anlan.lab1;

import android.app.AlertDialog;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.content.SharedPreferences;
import android.database.sqlite.SQLiteDatabase;
import android.media.MediaPlayer;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.os.SystemClock;
import android.support.v4.app.Fragment;
import android.support.v4.app.FragmentManager;
import android.support.v4.app.FragmentTransaction;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.MenuItem;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ImageView;
import android.widget.PopupMenu;
import android.widget.TextView;
import android.widget.Toast;

import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.text.DecimalFormat;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Timer;
import java.util.TimerTask;

public class GameFragment extends Fragment{
    private final String ACTION_LEVEL_CHANGE = "club.anlan.lab1.LEVEL_CHANGE";
    static final String TAG="Handler";
    static final int HANDLER_TEST=1;
    private int level;

    //所有ImageView的id
    private int[] imageViewIds = {R.id.image01, R.id.image02, R.id.image03, R.id.image04, R.id.image05,
            R.id.image06, R.id.image07, R.id.image08, R.id.image09, R.id.image10, R.id.image11,
            R.id.image12, R.id.image13, R.id.image14, R.id.image15, R.id.image16, R.id.image17,
            R.id.image18, R.id.image19, R.id.image20, R.id.image21, R.id.image22, R.id.image23,
            R.id.image24, R.id.image25, R.id.image26, R.id.image27, R.id.image28, R.id.image29,
            R.id.image30, R.id.image31, R.id.image32, R.id.image33, R.id.image34, R.id.image35,
            R.id.image36, R.id.image37, R.id.image38, R.id.image39, R.id.image40, R.id.image41,
            R.id.image42, R.id.image43, R.id.image44, R.id.image45, R.id.image46, R.id.image47,
            R.id.image48, R.id.image49, R.id.image50, R.id.image51, R.id.image52, R.id.image53,
            R.id.image54, R.id.image55, R.id.image56, R.id.image57, R.id.image58, R.id.image59,
            R.id.image60, R.id.image61, R.id.image62, R.id.image63, R.id.image64, R.id.image65,
            R.id.image66, R.id.image67, R.id.image68, R.id.image69, R.id.image70, R.id.image71,
            R.id.image72
    };
    //所有图片的id
    private int[] imageIds = {R.drawable.img0, R.drawable.img01, R.drawable.img02, R.drawable.img03, R.drawable.img04, R.drawable.img05,
            R.drawable.img06, R.drawable.img07, R.drawable.img08, R.drawable.img09, R.drawable.img10, R.drawable.img11,
            R.drawable.img12, R.drawable.img13, R.drawable.img14, R.drawable.img15, R.drawable.img16, R.drawable.img17,
            R.drawable.img18, R.drawable.img19, R.drawable.img20, R.drawable.img21,
    };
    private int[] curImageViews; // 用于随机生成地图
    private int[] curImages;    // 用于保存当前所有的图像id
    private int[][] map;    // 与ImageView对应的地图(存放的image view id)
    private boolean[][] curMap;     // 保存目前的地图的状态
    private boolean[][] usedNode;     // 标记
    private int curImageNum;   // 保存未消除的图像的数目
    static int[][] moveXY = {
            {0,1},{1,0},{0,-1},{-1,0}
    };

    private ImageView imgFirstClicked;
    private ImageView imgSecondClicked;
    private Button btnMenu;
    private MediaPlayer clickMusic;
    private ClickMusicThread cmt0,cmt1,cmt2;

    // 弹出框
    private View view_custom;
    private AlertDialog alert = null;
    private AlertDialog.Builder builder = null;
    private Button btnSendBroadCast;
    private TextView usedTime;
    private EditText userName;

    private TextView timerView;
    private long baseTimer;

    // 数据存储
    private SharedPreferences sp;
    private String filename = "name_image";

    public GameFragment() {

    }

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState) {
        View view = inflater.inflate(R.layout.fg_game, container, false);
        return view;
    }

    public void onActivityCreated(Bundle savedInstanceState) {
        super.onActivityCreated(savedInstanceState);
        sp = getActivity().getSharedPreferences("config", Context.MODE_PRIVATE);


        final MyApplication myApplication = MyApplication.getInstance();
        GameFragment.this.baseTimer = SystemClock.elapsedRealtime();
        timerView = getActivity().findViewById(R.id.timerView);
        final Handler startTimehandler = new Handler(){
            public void handleMessage(android.os.Message msg) {
                if (null != timerView) {
                    timerView.setText((String) msg.obj);
                }
            }
        };
        new Timer("计时器").scheduleAtFixedRate(new TimerTask() {
            @Override
            public void run() {
                if(myApplication.isConunterPaused()){
                    String sTime = timerView.getText().toString();
                    int hour = Integer.parseInt(sTime.substring(0,2));
                    int minute = Integer.parseInt(sTime.substring(3,5));
                    int second = Integer.parseInt(sTime.substring(6,8));
                    int allTime = hour*3600+minute*60+second;
                    GameFragment.this.baseTimer = SystemClock.elapsedRealtime()-allTime*1000;
                }
                int time = (int)((SystemClock.elapsedRealtime() - GameFragment.this.baseTimer) / 1000);
                String hh = new DecimalFormat("00").format(time / 3600);
                String mm = new DecimalFormat("00").format(time % 3600 / 60);
                String ss = new DecimalFormat("00").format(time % 60);
                String timeFormat = new String(hh + ":" + mm + ":" + ss);
                Message msg = new Message();
                msg.obj = timeFormat;
                startTimehandler.sendMessage(msg);
            }

        }, 0, 1000L);

        map = new int[9][8];
        curMap = new boolean[9][8];
        usedNode = new boolean[9][8];
        curImageViews = new int[imageViewIds.length];
        curImageNum = imageViewIds.length;

        for (int i = 0; i < curImageViews.length; i++) {
            curImageViews[i] = imageViewIds[i];
        }

        // 用图来存储每个ImageView的id，方便判断是否联通
        int idindex = 0;
        for (int i = 0; i < map.length; i++) {
            for (int j = 0; j < map[i].length; j++) {
                map[i][j] = imageViewIds[idindex];
                curMap[i][j] = false;
                idindex++;
            }
        }

        // ---------- 生成地图 ---------
        int curImageViewNum = imageViewIds.length;
        while (curImageViewNum > 0) {

            // 随机选择一张图片

            level = 2;
            MyApplication application = (MyApplication) MyApplication.getInstance();
            if (application != null) {
                level = application.getLevle();
            }

            int imageInArray = (int) (Math.random() * level); //难度

            // 随机选择两个ImageView并加载这同一张图片
            for (int i = 0; i < 2; i++) {
                int ImageViewInArray = (int) (Math.random() * curImageViewNum);
                ImageView view = getActivity().findViewById(curImageViews[ImageViewInArray]);
                curImageViewNum -= 1;
                curImageViews[ImageViewInArray] = curImageViews[curImageViewNum]; //已经有Image的ImageView 不再参与随机
                view.setImageResource(imageIds[imageInArray]);
                view.setTag(imageIds[imageInArray]);    // 用于判断点击的是否是同一张图片
                view.setOnClickListener(new View.OnClickListener() {
                    @Override
                    public void onClick(View v) {
                        GameFragment.this.onClick(v);
                    }
                });
            }
        }
        // ------------------------------

        //---------- 菜单 ---------
        btnMenu = getActivity().findViewById(R.id.btn_menu);
        btnMenu.setOnClickListener(new Button.OnClickListener() {

            @Override
            public void onClick(View v) {
                final MyApplication myApplication = MyApplication.getInstance();
                myApplication.setConunterPaused(true);
                PopupMenu popup = new PopupMenu(getActivity(), v);
                popup.inflate(R.menu.menu_main);
                //绑定菜单项的点击事件
                popup.setOnMenuItemClickListener(new PopupMenu.OnMenuItemClickListener() {

                    @Override
                    public boolean onMenuItemClick(MenuItem item) {
                        switch (item.getItemId()) {
                            case R.id.rePlay:
                                rePlay();
                                break;
                            case R.id.changeLevel:
                                changeLevel();
                                break;
                            case R.id.reSet:
                                reSet();
                                break;
                            default:
                                break;
                        }
                        myApplication.setConunterPaused(false);
                        return false;
                    }
                });
                popup.show();
            }
        });
        //--------------------

        //-------- 游戏完毕弹出框 -------
        builder = new AlertDialog.Builder(getContext());
        final LayoutInflater inflater = getActivity().getLayoutInflater();
        view_custom = inflater.inflate(R.layout.success_alert, null,false);
        builder.setView(view_custom);
        builder.setCancelable(false);
        alert = builder.create();

        usedTime = view_custom.findViewById(R.id.text_usedTime);
        userName = view_custom.findViewById(R.id.edit_userName);
        btnSendBroadCast = view_custom.findViewById(R.id.btn_sendBroadCast);
        btnSendBroadCast.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                //将名字存储到本地
                FileOutputStream fileOutputStream = null;
                try {
                    fileOutputStream = getActivity().openFileOutput(filename, Context.MODE_PRIVATE);
                    fileOutputStream.write(userName.getText().toString().getBytes());
                } catch (FileNotFoundException e) {
                    e.printStackTrace();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                try {
                    fileOutputStream.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                Intent intent = new Intent();
                intent.setAction("updateRank");
                intent.putExtra("usedTime",usedTime.getText().toString());
                intent.putExtra("userName",userName.getText().toString());
                getActivity().sendBroadcast(intent);
                MyApplication.getInstance().setConunterPaused(false);
                alert.dismiss();
            }
        });
        //-------------------
    }


    // ---- 消除的点击
    public void onClick(View v) {
        boolean isRemoveTwo = false;
        if(imgFirstClicked == null){
            imgFirstClicked = (ImageView) v;
            imgFirstClicked.setBackgroundResource(R.drawable.img_border);
        }
        else if(imgSecondClicked == null){
            imgSecondClicked = (ImageView) v;
            if(imgSecondClicked.getId()==imgFirstClicked.getId()){
                imgSecondClicked = null;
                if(sp.getBoolean("swhClickMusic",false)){
                    cmt2 = new ClickMusicThread();
                    cmt2.setMusciType(2);
                    cmt2.run();
                }
                return;
            }
            isRemoveTwo = judge(imgFirstClicked,imgSecondClicked);
            if(isRemoveTwo==false){
                imgFirstClicked.setBackgroundResource(0);
                int lastId = imgSecondClicked.getId();
                imgFirstClicked = getActivity().findViewById(lastId);
                imgFirstClicked.setBackgroundResource(R.drawable.img_border);
                imgSecondClicked = null;
                if(sp.getBoolean("swhClickMusic",false)){
                    cmt1 = new ClickMusicThread();
                    cmt1.setMusciType(1);
                    cmt1.start();
                }
                Toast.makeText(getActivity(), "不行哟", Toast.LENGTH_SHORT).show();
            }
            else{
                imgFirstClicked.setVisibility(View.INVISIBLE);
                imgSecondClicked.setVisibility(View.INVISIBLE);
                imgFirstClicked = null;
                imgSecondClicked = null;
                curImageNum -= 2;
                if(sp.getBoolean("swhClickMusic",false)){
                    cmt0 = new ClickMusicThread();
                    cmt0.setMusciType(0);
                    cmt0.start();
                }
                Toast.makeText(getActivity(), "不错哟", Toast.LENGTH_SHORT).show();

                // ---- 是否消除完
                if(curImageNum==0){
                    try {
                        Thread.sleep(1000);
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                    popAlert();
                }
            }
        }
    }

    // ---------- 判断两张图片是否能消掉
    protected boolean judge(ImageView first, ImageView second){
        boolean flag = false;
        if(first.getId() == second.getId()){   // 两次点击的是一个地方
            second = null;
        }
        else if(first.getTag().equals(second.getTag())){    // 两次点击的图片是一样的
            int idFirst = first.getId();
            int idSecond = second.getId();
            int firstX=0,firstY=0;
            int secondX=0,secondY=0;

            // 得到两次点击的图片在虚拟地图的位置
            for(int i=0;i<map.length;i++){
                for(int j=0;j<map[i].length;j++){
                    if(idFirst==map[i][j]){
                        firstX = i;
                        firstY = j;
                    }
                    else if(idSecond==map[i][j]){
                        secondX = i;
                        secondY = j;
                    }
                }
            }
            // 判断这两张图片是否是可连通的
            if((firstX==0 && (secondX==0 || secondY==0 || secondY==7)) || (firstX==8 && (secondX==8 || secondY==0 || secondY==7)) || (firstY==0 && (secondY==0 || secondX==0 || secondX==8)) || (firstY==7 && (secondY==7 || secondX==0 || secondX==7))){ // 如果都在四周
                flag = true;
            }
            else{
                curMap[secondX][secondY] = true;
                flag = bfs(firstX,firstY,secondX,secondY);
                curMap[secondX][secondY] = false;
            }
            if(flag==true){
                curMap[firstX][firstY] = true;
                curMap[secondX][secondY] = true;
            }
        }
        return flag;
    }

    protected boolean bfs(int x, int y, int targetX, int targetY){
        initUsedNode();
        int nx = 0;
        int ny = 0;
        Queue<Node> q = new LinkedList<Node>();
        Node node = new Node(x,y,null);
        q.add(node);
        while (!q.isEmpty()){
            Node curNode = q.poll();
            for(int i=0;i<4;i++){
                nx = curNode.x+moveXY[i][0];
                ny = curNode.y+moveXY[i][1];
                if (nx < 0 || nx  > 8 || ny < 0 || ny > 7) {
                    continue;
                } else if (curMap[nx][ny] == true && usedNode[nx][ny] == false) {
                    usedNode[nx][ny] = true;
                    node = new Node(nx,ny,curNode);
                    q.add(node);
                }
                if (nx==targetX && ny ==targetY){
                    return true;
                }
            }
        }
        return false;
    }

    // 初始化使用过的点
    protected void initUsedNode(){
        for (int i = 0; i < curMap.length; i++) {
            for (int j = 0; j < curMap[i].length; j++) {
                usedNode[i][j] = false;
            }
        }
    }

    // ---- 重新排列 ----
    protected void reSet() {
        if (imgFirstClicked != null) {
            imgFirstClicked.setBackgroundResource(0);
        }

        int imageNum = curImageNum;  //得到此时未消除的图像数目
        curImages = new int[imageNum];
        // 获取所有的Image id
        for (int i = 0; i < curMap.length; i++) {
            for (int j = 0; j < curMap[i].length; j++) {
                if (curMap[i][j] == false) {
                    ImageView view = getActivity().findViewById(map[i][j]);
                    imageNum--;
                    curImages[imageNum] = (int) view.getTag();
                }
            }
        }
        // 打乱顺序
        for (int i = 0; i < curImages.length; i++) {
            int swapId = (int) (Math.random() * curImages.length);
            int temp = curImages[swapId];
            curImages[swapId] = curImages[i];
            curImages[i] = temp;
        }
        // 将乱序后的id赋给ImageView
        int allImageViewNum = 0;
        for (int i = 0; i < map.length; i++) {
            for (int j = 0; j < map[i].length; j++) {
                if (curMap[i][j] == false) {
                    ImageView view = getActivity().findViewById(map[i][j]);
                    view.setImageResource(curImages[imageNum]);
                    view.setTag(curImages[imageNum]);
                    imageNum++;
                }
            }
        }
    }

    // ---- 选择关卡 ----
    protected void changeLevel(){
        MyApplication myApplication = MyApplication.getInstance();
        FragmentTransaction fTransaction = getActivity().getSupportFragmentManager().beginTransaction();
        myApplication.hideAllFragment(fTransaction);
        ChangLevelFragment fgChangeLevel;
        if(myApplication.getFgLevel()==null){
            fgChangeLevel = new ChangLevelFragment();
            fTransaction.add(R.id.ly_content,fgChangeLevel);
            myApplication.setFgLevel(fgChangeLevel);
        }
        else
            fgChangeLevel = myApplication.getFgLevel();
        fTransaction.show(fgChangeLevel);
        fTransaction.commit();
    }

    // ---- 重新开始游戏 ----
    protected void rePlay(){
        for(int i=0;i<map.length;i++){
            for(int j=0;j<map[i].length;j++){
               if(curMap[i][j]==true){
                    ImageView view = getActivity().findViewById(map[i][j]);
                    view.setBackgroundResource(0);
                    view.setVisibility(View.VISIBLE);
                    curMap[i][j]=false;
               }
            }
        }
        curImageNum = imageViewIds.length;
        GameFragment.this.baseTimer = SystemClock.elapsedRealtime();
    }

    // ---- 弹出对话框 ----
    protected void popAlert(){
        MyApplication.getInstance().setConunterPaused(true);
        String sTime = timerView.getText().toString();
        int hour = Integer.parseInt(sTime.substring(0,2));
        int minute = Integer.parseInt(sTime.substring(3,5));
        int second = Integer.parseInt(sTime.substring(6,8));
        int allTime = hour*3600+minute*60+second;
        usedTime.setText(allTime+"s");
        alert.show();
    }


    class Node{
        int x,y;
        Node parent;
        char dir;

        Node(){}

        Node(int x, int y, Node parent){
            this.x = x;
            this.y = y;
            this.parent = parent;
        }

        public boolean equals(Node node) {
            if(this.x==node.x && this.y==node.y){
                return true;
            }
            return false;
        }
    }

    //---  点击音效 ---//
    public class ClickMusicThread extends Thread {
        private int musicType;

        @Override
        public void run() {
            clickMusic.start();
        }

        public void setMusciType(int musicType) {
            this.musicType = musicType;
            switch (musicType){
                case 0:
                    clickMusic = MediaPlayer.create(getActivity(),R.raw.clear);
                    break;
                case 1:
                    clickMusic = MediaPlayer.create(getActivity(),R.raw.error);
                    break;
                case 2:
                    clickMusic = MediaPlayer.create(getActivity(),R.raw.repeat);
                    break;
            }
        }

        public int getMusciType() {
            return musicType;
        }
    }
}
