package club.anlan.lab1;

import android.app.Application;
import android.support.v4.app.FragmentTransaction;

public class MyApplication extends Application {
    private int levle;
    private boolean isConunterPaused = false;
    private InfoFragment fgInfo;
    private RankFragment fgRank;
    private GameFragment fgGame;
    private ChangLevelFragment fgLevel;
    private static MyApplication instance;

    public MyApplication(){
    }

    @Override
    public void onCreate() {
        super.onCreate();
        this.setLevle(10);
        instance = this;
    }

    public static MyApplication getInstance() {
        return instance;
    }

    public int getLevle() {
        return levle;
    }

    public void setLevle(int levle) {
        this.levle = levle;
    }

    public InfoFragment getFgInfo() {
        return fgInfo;
    }

    public void setFgInfo(InfoFragment fgInfo) {
        this.fgInfo = fgInfo;
    }

    public RankFragment getFgRank() {
        return fgRank;
    }

    public void setFgRank(RankFragment fgRank) {
        this.fgRank = fgRank;
    }

    public GameFragment getFgGame() {
        return fgGame;
    }

    public void setFgGame(GameFragment fgGame) {
        this.fgGame = fgGame;
    }

    public ChangLevelFragment getFgLevel() {
        return fgLevel;
    }

    public void setFgLevel(ChangLevelFragment fgLevel) {
        this.fgLevel = fgLevel;
    }

    public boolean isConunterPaused() {
        return isConunterPaused;
    }

    public void setConunterPaused(boolean conunterPaused) {
        isConunterPaused = conunterPaused;
    }

    //隐藏所有Fragment
    public void hideAllFragment(FragmentTransaction fragmentTransaction){
        if(this.getFgInfo() != null)
            fragmentTransaction.hide(this.getFgInfo());
        if(this.getFgLevel() != null)
            fragmentTransaction.hide(this.getFgLevel());
        if(this.getFgGame() != null)
            fragmentTransaction.hide(this.getFgGame());
        if(this.getFgRank() != null){
            fragmentTransaction.hide(this.getFgRank());
        }
    }

}
