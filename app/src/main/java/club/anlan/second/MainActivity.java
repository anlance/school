package club.anlan.second;

import android.app.Activity;
import android.drm.DrmStore;
import android.os.Bundle;
import android.view.ActionMode;
import android.view.ContextMenu;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.MenuItem;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.PopupMenu;
import android.widget.PopupMenu.OnMenuItemClickListener;
import android.widget.TextView;
import android.widget.Toast;


public class MainActivity extends Activity implements OnClickListener,OnMenuItemClickListener  {
    private ImageView imgDog;
    private TextView txt;
    private android.view.ActionMode actionMode;     // 在全局范围保存上下文操作模式示例
    private Button button1;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        txt = (TextView)findViewById(R.id.txt);
        button1 = (Button)findViewById(R.id.button1);
        button1.setOnClickListener(this);
//        button2 = (Button)findViewById(R.id.button2);
//        button2.setOnClickListener(this);
        //为视图空间绑定上下文菜单
        registerForContextMenu(txt);

        // 实现ActionMode.CallBack接口
        final ActionMode.Callback callback = new ActionMode.Callback() {
            @Override
            public boolean onCreateActionMode(ActionMode mode, Menu menu) {
                MenuInflater inflater = mode.getMenuInflater();
                inflater.inflate(R.menu.menu_context,menu);
                return true;
            }

            @Override
            public boolean onPrepareActionMode(ActionMode mode, Menu menu) {
                return false;
            }

            @Override
            public boolean onActionItemClicked(ActionMode mode, MenuItem item) {
                switch (item.getItemId()) {
                    case R.id.yes:
                        Toast.makeText(MainActivity.this, "废话，用你说···", Toast.LENGTH_SHORT).show();
                        break;
                    case R.id.no:
                        Toast.makeText(MainActivity.this, "关你什么事···", Toast.LENGTH_SHORT).show();
                        break;
                    case 3:
                        Toast.makeText(MainActivity.this,"你才应该答应我不要做舔狗",Toast.LENGTH_SHORT).show();
                        break;
                    default:
                        return false;
                }
                return true;
            }

            //取消保存的ActionMode示例， 避免影响下一次ActionMode的创建
            @Override
            public void onDestroyActionMode(ActionMode mode) {
                actionMode = null;
            }
        };

        findViewById(R.id.dog).setOnLongClickListener( new View.OnLongClickListener(){
            @Override
            public boolean onLongClick(View v) {
                if(actionMode != null){
                    return false;
                }
                actionMode = startActionMode(callback);
                v.setSelected(true);    // 设置view的状态为选中
                return true;
            }
        });
    }

    //创建上下文菜单
    @Override
    public void onCreateContextMenu(ContextMenu menu, View v, ContextMenu.ContextMenuInfo menuInfo) {
        super.onCreateContextMenu(menu, v, menuInfo);

        getMenuInflater().inflate(R.menu.menu_context, menu);
        menu.add(0,3,0,"我觉得");
    }

    //上下文菜单的触发事件
    @Override
    public boolean onContextItemSelected(MenuItem item) {
        switch (item.getItemId()) {
            case R.id.yes:
                Toast.makeText(this, "废话，用你说···", Toast.LENGTH_SHORT).show();
                break;
            case R.id.no:
                Toast.makeText(this, "关你什么事···", Toast.LENGTH_SHORT).show();
                break;
            case 3:
                Toast.makeText(this,"你才应该答应我不要做舔狗",Toast.LENGTH_SHORT).show();
                break;
            default:
                break;
        }
        return super.onContextItemSelected(item);
    }

    // 点击按钮后，加载弹出式菜单
    @Override
    public void onClick(View v) {
        //创建弹出式菜单对象（最低版本11）
        //第二个参数是绑定的那个View
        PopupMenu popup = new PopupMenu(this, v);
        popup.inflate(R.menu.menu_pop);
        //如果是在API 14及以前版本，上面一行代码要替换为：
        // MenuInflater inflater = popup.getMenuInflater();
        // inflater.inflate(R.menu.menu_main, popup.getMenu());

        //绑定菜单项的点击事件
        popup.setOnMenuItemClickListener(this);
        popup.show();
    }

    @Override
    public boolean onMenuItemClick(MenuItem item) {
        switch (item.getItemId()) {
            case R.id.see:
                Toast.makeText(this, "他好像一条狗啊···", Toast.LENGTH_SHORT).show();
                break;

            case R.id.see2:
                Toast.makeText(this, "原来你也是···", Toast.LENGTH_SHORT).show();
                break;
            default:
                break;
        }
        return false;
    }
}
