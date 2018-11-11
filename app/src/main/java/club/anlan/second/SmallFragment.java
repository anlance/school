package club.anlan.second;


import android.os.Bundle;
import android.support.v4.app.Fragment;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;


public class SmallFragment extends Fragment {

    private ImageView smallImage;
    int imgID[]={R.id.small_3_1,R.id.small_3_2,R.id.small_3_3,R.id.small_3_4,R.id.small_3_5,R.id.small_3_6};

    public void onActivityCreated(Bundle savedInstanceState) {
        super.onActivityCreated(savedInstanceState);
        final ImageView bigImage = (ImageView) getActivity().findViewById(R.id.big_image);
        for (int i=0;i<imgID.length;i++){
            smallImage = (ImageView)getView().findViewById(imgID[i]);
            if (smallImage!=null){
                smallImage.setOnClickListener(new View.OnClickListener() {
                    @Override
                    public void onClick(View view) {
                        ImageView v =(ImageView)view;
                        bigImage.setImageDrawable(v.getDrawable());
                    }
                });
            }
        }
    }

    public SmallFragment() {
        // Required empty public constructor
    }


    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState) {
        return inflater.inflate(R.layout.fragment_small, container, false);
    }
}
