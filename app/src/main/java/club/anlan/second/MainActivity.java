package club.anlan.second;

import android.content.res.Configuration;
import android.support.v4.app.Fragment;
import android.support.v4.app.FragmentManager;
import android.support.v4.app.FragmentTransaction;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.ImageView;

public class MainActivity extends AppCompatActivity {

    private ImageView bigImage;
    Fragment sf;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        bigImage = (ImageView) findViewById(R.id.big_image);

        sf = new SmallFragment();
        if (this.getResources().getConfiguration().orientation == Configuration.ORIENTATION_PORTRAIT) {
            sf.setArguments(getIntent().getExtras());
            FragmentManager manager = getSupportFragmentManager();
            FragmentTransaction transaction = manager.beginTransaction();
            transaction.add(R.id.fragment_small, sf, "smallfragment");
            transaction.commit();
        } else {
            FragmentManager manager = getSupportFragmentManager();
            sf = (SmallFragment) manager.findFragmentByTag("smallfragment");
            FragmentTransaction transaction = manager.beginTransaction();
            if (sf != null) transaction.remove(sf);
            transaction.commit();
        }

    }

    public void updateImage(ImageView img) {
        bigImage.setImageDrawable(img.getDrawable());
    }


}
