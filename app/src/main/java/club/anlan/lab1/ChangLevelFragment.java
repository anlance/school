package club.anlan.lab1;

import android.os.Bundle;
import android.support.v4.app.Fragment;
import android.support.v4.app.FragmentTransaction;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.RatingBar;
import android.widget.TextView;

public class ChangLevelFragment extends Fragment{
    private RatingBar rbLevel;
    private TextView tx;
    private ImageView iv;
    private int level;
    private Button btn_doChange;
    private GameFragment fgGame;

    public ChangLevelFragment() {

    }

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState) {
        View view = inflater.inflate(R.layout.fg_level,container,false);
        return view;
    }

    public void onActivityCreated(Bundle savedInstanceState) {
        super.onActivityCreated(savedInstanceState);
        rbLevel = getActivity().findViewById(R.id.level);
        btn_doChange = getActivity().findViewById(R.id.btn_changeLevel);
        tx = getActivity().findViewById(R.id.txt_cur_level);
        iv = getActivity().findViewById(R.id.img_level);
        // 显示当前的level
        final MyApplication application = (MyApplication) MyApplication.getInstance();
        if(application!=null){
            level = application.getLevle();
        }
        else{
            level = 10;
            application.setLevle(level);
        }
        switch (level){
            case 5:
                rbLevel.setRating(1);
                tx.setText("黑铁");
                iv.setImageResource(R.drawable.iron);
                break;
            case 10:
                rbLevel.setRating(2);
                tx.setText("青铜");
                iv.setImageResource(R.drawable.bronze);
                break;
            case 15:
                rbLevel.setRating(3);
                tx.setText("白银");
                iv.setImageResource(R.drawable.silver);
                break;
            case 19:
                rbLevel.setRating(4);
                tx.setText("黄金");
                iv.setImageResource(R.drawable.gold);
                break;
            case 22:
                rbLevel.setRating(5);
                tx.setText("钻石");
                iv.setImageResource(R.drawable.diamond);
                break;
        }

        rbLevel.setOnRatingBarChangeListener(new RatingBar.OnRatingBarChangeListener() {
            @Override
            public void onRatingChanged(RatingBar ratingBar, float rating, boolean fromUser) {

                level = (int) rating;
                MyApplication application = (MyApplication) getActivity().getApplicationContext();
                switch (level){
                    case 1:
                        application.setLevle(5);
                        tx.setText("黑铁");
                        iv.setImageResource(R.drawable.iron);
                        break;
                    case 2:
                        application.setLevle(10);
                        tx.setText("青铜");
                        iv.setImageResource(R.drawable.bronze);
                        break;
                    case 3:
                        application.setLevle(15);
                        tx.setText("白银");
                        iv.setImageResource(R.drawable.silver);
                        break;
                    case 4:
                        application.setLevle(19);
                        tx.setText("黄金");
                        iv.setImageResource(R.drawable.gold);
                        break;
                    case 5:
                        application.setLevle(22);
                        tx.setText("钻石");
                        iv.setImageResource(R.drawable.diamond);
                        break;
                }
            }
        });

        btn_doChange.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                FragmentTransaction fTransaction = getActivity().getSupportFragmentManager().beginTransaction();
                // 移除旧的
                application.hideAllFragment(fTransaction);
                if(application.getFgGame()!=null){
                    fgGame = application.getFgGame();
                    fTransaction.remove(fgGame);
                }
                // 添加新的
                fgGame = new GameFragment();
                application.setFgGame(fgGame);
                fTransaction.add(R.id.ly_content,fgGame);
                fTransaction.show(fgGame);
                fTransaction.commit();
            }
        });
    }
}
