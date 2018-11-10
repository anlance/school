package club.anlan.second;

import android.content.Intent;
import android.media.Image;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.ImageView;

public class MainActivity extends AppCompatActivity {
    private ImageView bigImage;
    private ImageView smallImage;
    int imgID[]={R.id.small_3_1,R.id.small_3_2,R.id.small_3_3,R.id.small_3_4,R.id.small_3_5,R.id.small_3_6};

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        bigImage = (ImageView)findViewById(R.id.big_image);
        showImage();
    }

    protected void showImage(){
        for(int i=0;i<imgID.length;i++){
            smallImage = (ImageView)findViewById(imgID[i]);
            smallImage.setOnClickListener(new View.OnClickListener(){

                @Override
                public void onClick(View v) {
                    ImageView img = (ImageView) v;
                    bigImage.setImageDrawable(img.getDrawable());
                }
            });
        }
    }


}
