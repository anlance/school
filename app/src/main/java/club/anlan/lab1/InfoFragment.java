package club.anlan.lab1;

import android.content.Context;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.support.v4.app.Fragment;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.CompoundButton;
import android.widget.Switch;

public class InfoFragment extends Fragment implements Switch.OnCheckedChangeListener{
    private Switch swhBgMusic;
    private Switch swhClickMusic;
    private SharedPreferences sp;

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState) {
        View view = inflater.inflate(R.layout.fg_info,container,false);
//        TextView txt_content = (TextView) view.findViewById(R.id.txt_content);
//        txt_content.setText(content);
        return view;
    }

    public void onActivityCreated(Bundle savedInstanceState) {
        super.onActivityCreated(savedInstanceState);
        sp = getActivity().getSharedPreferences("config", Context.MODE_PRIVATE);
        swhBgMusic = getActivity().findViewById(R.id.swh_bg);
        swhClickMusic = getActivity().findViewById(R.id.swh_click);
        swhBgMusic.setChecked(sp.getBoolean("swhBgMusic",false));
        swhClickMusic.setChecked(sp.getBoolean("swhClickMusic",false));
        swhBgMusic.setOnCheckedChangeListener(this);
        swhClickMusic.setOnCheckedChangeListener(this);
    }

    @Override
    public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
        switch (buttonView.getId()){
            case R.id.swh_bg:
                saveData("swhBgMusic",isChecked);
                break;
            case R.id.swh_click:
                saveData("swhClickMusic",isChecked);
                break;
        }
    }

    private void saveData(String swhBtn, Boolean isChecked) {
        SharedPreferences.Editor editor = sp.edit();//获取编辑器
        editor.putBoolean(swhBtn, isChecked);//写入数据
        editor.commit();//提交
    }
}
