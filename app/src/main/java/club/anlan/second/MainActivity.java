package club.anlan.second;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.MotionEvent;
import android.view.View;
import android.widget.ImageView;


public class MainActivity extends AppCompatActivity {
    protected static final String TAG="MyAndroid";
    boolean flag = false;
    ImageView v;
    float lastX = 0;
    float lastY = 0;
    int imgID[]={R.id.imageClothes,R.id.imageGlasses,R.id.imageShoes};

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }


    @Override
    public boolean onTouchEvent(MotionEvent event) {
        switch (event.getAction()){
            case MotionEvent.ACTION_DOWN:
                flag = false;
                lastX = (float) event.getRawX();
                lastY = (float) event.getRawY();
                Log.d(MainActivity.TAG, "1"+flag);
                for(int i=0;i<imgID.length;i++){
                    v = findViewById(imgID[i]);
                    if(lastX>v.getLeft() && lastX<v.getLeft()+v.getWidth() && lastY>v.getTop() && lastY<v.getTop()+v.getHeight()){
                        flag = true;
                        Log.d(MainActivity.TAG, "2:----------"+flag);
                        Log.d(MainActivity.TAG, "x: "+lastX+"    y: "+lastY);
                        Log.d(MainActivity.TAG, "le: "+v.getLeft() + "     le+we:"+(v.getLeft()+v.getWidth()));
                        Log.d(MainActivity.TAG, "Top: "+v.getTop()+ "     top+he:"+(v.getTop()+v.getHeight()));
                        break;
                    }
                }
                break;
            case MotionEvent.ACTION_MOVE:
                Log.d(MainActivity.TAG, "4"+flag);
                if(flag){
                    Log.d(TAG, "5"+v);
                    float moveX = (float) (event.getRawX() - lastX);
                    float moveY = (float) (event.getRawY() - lastY);
                    if (moveX != 0 && moveY != 0) {
                        int l = (int) (v.getLeft() + moveX);
                        int r = (int) (v.getRight() + moveX);
                        int t = (int) (v.getTop() + moveY);
                        int b = (int) (v.getBottom() + moveY);

                        lastX = (float) event.getRawX();
                        lastY = (float) event.getRawY();

                        v.layout(l, t, r, b);
                    }
                }
                break;
            case MotionEvent.ACTION_UP:
                break;
            case MotionEvent.ACTION_CANCEL:
                break;
        }
        return false;
    }

    public void addGlasses(View view) {
        ImageView imageView = (ImageView)findViewById(R.id.imageGlasses);
        imageView.setImageResource(R.drawable.add_glasses);
    }

    public void delGlasses(View view) {
        ImageView imageView = (ImageView)findViewById(R.id.imageGlasses);
        imageView.setImageResource(R.drawable.nothing);
    }

    public void addShoes(View view) {
        ImageView imageView = (ImageView)findViewById(R.id.imageShoes);
        imageView.setImageResource(R.drawable.add_shoes);
    }

    public void delShoes(View view) {
        ImageView imageView = (ImageView)findViewById(R.id.imageShoes);
        imageView.setImageResource(R.drawable.nothing);
    }

    public void girlToEvening(View view) {
        ImageView imageView = (ImageView)findViewById(R.id.imageClothes);
        imageView.setImageResource(R.drawable.girl_evening);
    }
    public void girlToSummer(View view) {
        ImageView imageView = (ImageView)findViewById(R.id.imageClothes);
        imageView.setImageResource(R.drawable.girl_summer);
    }

    public void girlToSpring(View view) {
        ImageView imageView = (ImageView)findViewById(R.id.imageClothes);
        imageView.setImageResource(R.drawable.girl_spring);
    }

    public void girlToHot(View view) {
        ImageView imageView = (ImageView)findViewById(R.id.imageClothes);
        imageView.setImageResource(R.drawable.nothing);
    }

}
