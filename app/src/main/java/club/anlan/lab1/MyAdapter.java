package club.anlan.lab1;

import android.content.Context;
import android.support.v7.widget.RecyclerView;
import android.support.v7.widget.RecyclerView.ViewHolder;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.ImageView;
import android.widget.TextView;

import java.util.LinkedList;

public class MyAdapter extends BaseAdapter{
    private Context context;
    private LinkedList<UserRank> userRanks;

    public MyAdapter(){

    }

    public MyAdapter(LinkedList<UserRank> userRanks, Context context){
        this.userRanks = userRanks;
        this.context = context;
    }

    @Override
    public int getCount() {
        return userRanks.size();
    }

    @Override
    public Object getItem(int position) {
        return null;
    }

    @Override
    public long getItemId(int position) {
        return position;
    }

    @Override
    public View getView(int position, View convertView, ViewGroup parent) {
        convertView = LayoutInflater.from(context).inflate(R.layout.list_rank_item,parent,false);
        TextView txt_number = (TextView) convertView.findViewById(R.id.txt_list_number);
        TextView txt_username = (TextView) convertView.findViewById(R.id.txt_list_username);
        TextView txt_usedtime = (TextView) convertView.findViewById(R.id.txt_list_userdtime);
        TextView txt_createdtime = (TextView) convertView.findViewById(R.id.txt_list_createdtime);
        txt_number.setText(userRanks.get(position).getNumber()+" ");
        txt_username.setText(userRanks.get(position).getUserName());
        txt_usedtime.setText(userRanks.get(position).getUsedTime());
        txt_createdtime.setText(userRanks.get(position).getCreatedTime());
        return convertView;
    }
}
