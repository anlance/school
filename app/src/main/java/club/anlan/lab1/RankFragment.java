package club.anlan.lab1;

import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.os.Bundle;
import android.support.v4.app.Fragment;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ListView;
import java.text.SimpleDateFormat;
import java.util.Collections;
import java.util.Date;
import java.util.LinkedList;


public class RankFragment extends Fragment implements MyReceiver.MsgCallBack{
    private LinkedList<UserRank> userRankList = null;
    private Context context;
    private MyAdapter myAdapter = null;
    private ListView list_rank;

    // SQlite数据库
    private SQLiteDatabase db;
    private DatabaseHelper helper;

    public RankFragment() {

    }

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState) {
        View view = inflater.inflate(R.layout.fg_rank,container,false);
        return view;
    }


    public void onActivityCreated(Bundle savedInstanceState) {
        super.onActivityCreated(savedInstanceState);
        helper = new DatabaseHelper(getActivity(),"rankDB.db",null,1);
        db=helper.getWritableDatabase();

        list_rank = getActivity().findViewById(R.id.list_rank);

        if(userRankList==null){
            userRankList = new LinkedList<UserRank>();
            Cursor cursor = db.rawQuery("select * from rank",null);
            cursor.moveToFirst();
            int dbNumber = 0;
            String dbUserName = "";
            String dbUsedTime = "";
            String dbCreatedTime = "";
            while (!cursor.isAfterLast()){
                dbNumber=cursor.getInt(0);
                dbUserName=cursor.getString(1);
                dbUsedTime=cursor.getString(2);
                dbCreatedTime=cursor.getString(3);
                userRankList.add(new UserRank(dbNumber,dbUserName,dbUsedTime,dbCreatedTime));
                cursor.moveToNext();
            }
        }
        myAdapter = new MyAdapter(userRankList, getContext());
        list_rank.setAdapter(myAdapter);
    }


    @Override
    public void setRankInfo(String usedTime, String userName) {
        //do
        Date date = new Date();
        SimpleDateFormat dateFormat= new SimpleDateFormat("yyyy-MM-dd :hh:mm:ss");
        String currentTime = dateFormat.format(date);



        list_rank = getActivity().findViewById(R.id.list_rank);

        userRankList.add(new UserRank(userRankList.size()+1,userName,usedTime,currentTime));
        Collections.sort(userRankList);

        // 插入数据库
        ContentValues cv = new ContentValues();
        cv.put("number",userRankList.size());
        cv.put("username",userName);
        cv.put("usedTime",usedTime);
        cv.put("createdTime",currentTime);
        db.insert("rank",null,cv);

        myAdapter = new MyAdapter(userRankList, getContext());
        list_rank.setAdapter(myAdapter);

    }

}
