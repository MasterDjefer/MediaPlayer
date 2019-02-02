package com.predator.explorer;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.os.Environment;
import android.view.View;
import android.widget.AdapterView;
import android.widget.AdapterViewFlipper;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.ListView;
import android.widget.TextView;
import android.widget.Toast;

import org.w3c.dom.Text;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.LineNumberReader;
import java.util.ArrayList;
import java.util.Collections;

/**
 * Created by Predator on 06.05.2018.
 */

public class ExplorerActivity extends Activity implements View.OnClickListener, AdapterView.OnItemClickListener {

    private static int MUSIC_PATH_CODE = 155;

    private TextView textPath;
    private ListView foldersList;
    private Button buttonCloseExplorer;

    private ArrayAdapter<String> adapter;
    private File mainDirectory;
    private ArrayList<String> listFiles;
    private File lastDirectory;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_explorer);

        textPath = (TextView)findViewById(R.id.textPath);
        foldersList = (ListView)findViewById(R.id.foldersList);
        buttonCloseExplorer = (Button)findViewById(R.id.buttonCloseExplorer);
        buttonCloseExplorer.setOnClickListener(this);

        if (isDeviceReadyToRead())
        {
            mainDirectory = Environment.getExternalStorageDirectory();
            textPath.setText(mainDirectory.getPath());
            lastDirectory = mainDirectory;
            ArrayList<String> listFiles = getFilesFromDirectory(mainDirectory);
            if (listFiles != null)
            {
                Collections.sort(listFiles);
                listFiles.add(0, "..");
                adapter = new ArrayAdapter<String>(this, android.R.layout.simple_list_item_1, listFiles);
                foldersList.setAdapter(adapter);

                foldersList.setOnItemClickListener(this);
            }
            else
            {
                Toast.makeText(ExplorerActivity.this, "error", Toast.LENGTH_SHORT).show();
            }
        }
        else
        {
            Toast.makeText(ExplorerActivity.this, "error", Toast.LENGTH_SHORT).show();
        }
    }

    private boolean isDeviceReadyToRead()
    {
        String s = Environment.getExternalStorageState();
        return (s.equals(Environment.MEDIA_MOUNTED) || s.equals(Environment.MEDIA_MOUNTED_READ_ONLY));
    }

    private ArrayList<String> getFilesFromDirectory(File file)
    {
        File[] files = file.listFiles();
        if (files == null)
        {
            return null;
        }
        ArrayList<String> listFiles = new ArrayList<>();
        for (int i = 0; i < files.length; ++i)
        {
            if (files[i].isDirectory())
            {
                listFiles.add(files[i].getName());
            }
            else
            if (files[i].isFile())
            {
                listFiles.add(files[i].getName() + "~");
            }
        }
        return listFiles;
    }

    @Override
    public void onClick(View v) {
        if (v.getId() == buttonCloseExplorer.getId())
        {
            finish();
        }
    }

    private boolean isFile(String fileName)
    {
        return fileName.charAt(fileName.length() - 1) == '~';
    }

    private boolean isMusic(String s)
    {
        return s.lastIndexOf(".mp3") == s.length() - 4;
    }
    private boolean isImage(String s)
    {
        return s.lastIndexOf(".jpg") == s.length() - 4;
    }
    private boolean isText(String s)
    {
        return s.lastIndexOf(".txt") == s.length() - 4;
    }

    private boolean isDirectoryBack(String fileName)
    {
        return fileName.equals("..");
    }

    private String getLastFolderName(String path)
    {
        int index = path.lastIndexOf('/');
        path = path.substring(0, index);
        index = path.lastIndexOf('/');
        path = path.substring(index + 1, path.length());

        if (path.equals("storage"))
            return "/" + path;

        return path;
    }

    private File getLastDirectory(String path)
    {

        int index = path.lastIndexOf('/');
        path = path.substring(0, index);
        index = path.lastIndexOf('/');
        path = path.substring(0, index);

        return new File(path);
    }

    @Override
    public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
        if (parent.getAdapter().equals(adapter))
        {
            String sDir = parent.getAdapter().getItem(position).toString();

            if (!isFile(sDir))
            {
                if (isDirectoryBack(sDir))
                {
                    sDir = getLastFolderName(lastDirectory.getPath());
                    lastDirectory = getLastDirectory(lastDirectory.getPath());
                }

                File newDirectory = new File(lastDirectory, sDir);
                textPath.setText(newDirectory.getPath());
                lastDirectory = newDirectory;
                listFiles = getFilesFromDirectory(newDirectory);
                Collections.sort(listFiles);
                listFiles.add(0, "..");
                adapter.clear();
                adapter.addAll(listFiles);
            }
            else
            {
                sDir = sDir.replaceAll("~", "");
                if (isMusic(sDir))
                {
//                    Intent intent = new Intent(ExplorerActivity.this, MusicPlayerActivity.class);
//                    intent.putExtra("music", lastDirectory.getPath() + "/" + sDir);
//                    startActivity(intent);

//                    Toast.makeText(ExplorerActivity.this, "choosed", Toast.LENGTH_SHORT).show();
                    Intent intent = new Intent();
                    intent.putExtra("music", lastDirectory.getPath() + "/" + sDir);
                    setResult(Activity.RESULT_OK, intent);
                    finish();
                }
                else
                if (isImage(sDir))
                {
                    Intent intent = new Intent(ExplorerActivity.this, ImageBrowserActivity.class);
                    intent.putExtra("image", lastDirectory.getPath() + "/" + sDir);
                    startActivity(intent);
                }
                else
                if (isText(sDir))
                {
                    File f = new File(lastDirectory, "dir");
                    if (!f.exists())
                    {
                        f.mkdir();
                    }


                    try {
                        LineNumberReader reader = new LineNumberReader(new FileReader(lastDirectory.getPath() + "/" + sDir));
                        String s = "";
                        while(true)
                        {
                            String text = reader.readLine();
                            if (text == null)
                                break;
                            s += text + "\n";
                        }
                        reader.close();
                        Toast.makeText(ExplorerActivity.this, s, Toast.LENGTH_SHORT).show();

                    } catch (FileNotFoundException e) {
                        Toast.makeText(ExplorerActivity.this, "Error not found", Toast.LENGTH_SHORT).show();
                        e.printStackTrace();
                    } catch (IOException e) {
                        Toast.makeText(ExplorerActivity.this, "Error read", Toast.LENGTH_SHORT).show();
                        e.printStackTrace();
                    }
                }
                else
                {
                    Toast.makeText(ExplorerActivity.this, "Unknown file!", Toast.LENGTH_SHORT).show();
                }
            }
        }
    }
}
