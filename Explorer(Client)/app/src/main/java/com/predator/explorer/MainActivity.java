package com.predator.explorer;

import android.app.Activity;
import android.content.Intent;
import android.os.AsyncTask;
import android.os.StrictMode;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.KeyEvent;
import android.view.View;
import android.view.WindowManager;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

import org.w3c.dom.Text;

import java.io.IOException;
import java.net.Socket;
import java.net.UnknownHostException;

public class MainActivity extends Activity implements View.OnClickListener{

    private static int MUSIC_PATH_CODE = 155;
    private Button buttonOpenExplorer;
    private Button buttonFindServer;
    private Button buttonCloseConnection;
    private Button buttonPlayPause;
    private Button buttonLeft;
    private Button buttonRight;

    private TextView textStatus;

    private boolean isSearching = false;

    ClientSocket clientSocket;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        buttonOpenExplorer = (Button)findViewById(R.id.buttonOpenExplorer);
        buttonOpenExplorer.setOnClickListener(this);

        buttonFindServer = (Button)findViewById(R.id.buttonFindServer);
        buttonFindServer.setOnClickListener(this);

        buttonCloseConnection = (Button)findViewById(R.id.buttonCloseConnection);
        buttonCloseConnection.setOnClickListener(this);

        buttonPlayPause = (Button)findViewById(R.id.buttonPlayPause);
        buttonPlayPause.setOnClickListener(this);

        buttonLeft = (Button)findViewById(R.id.buttonLeft);
        buttonLeft.setOnClickListener(this);

        buttonRight = (Button)findViewById(R.id.buttonRight);
        buttonRight.setOnClickListener(this);

        textStatus = (TextView) findViewById(R.id.textStatus);
        textStatus.setOnClickListener(this);

        clientSocket = new ClientSocket();
    }

    @Override
    protected void onDestroy()
    {
        super.onDestroy();
        try {
            clientSocket.closeConnection();
            Log.d("||||||||||", "destroyed");
        } catch (Exception e) {
            Log.d("||||||||||", "error while destroyed");
            e.printStackTrace();
        }
    }


    @Override
    public void onClick(View v) {
        if (v.getId() == buttonOpenExplorer.getId())
        {
            Intent intent = new Intent(MainActivity.this, ExplorerActivity.class);
            startActivityForResult(intent, MUSIC_PATH_CODE);
        } else
        if (v.getId() == buttonFindServer.getId())
        {
            if (clientSocket.isConneted())
                return;
            if (isSearching)
                return;
            isSearching = true;
            new Thread()
            {
                @Override
                public void run()
                {
                    String msg = "";
                    try {
                        msg = clientSocket.connect();
                        isSearching = false;
                    }
                    catch(Exception e)
                    {
                        Log.d("|||||||||", "error connect");
                        e.printStackTrace();
                    }


                    final String finalMsg = msg;
                    MainActivity.this.runOnUiThread(new Runnable() {
                        public void run() {
                            textStatus.setText(finalMsg);
                        }
                    });
                }
            }.start();
        } else
        if (v.getId() == buttonCloseConnection.getId())
        {
            try {
                clientSocket.closeConnection();
            } catch (Exception e) {
                Log.d("|||||||||", "error close connection");
                e.printStackTrace();
            }
            textStatus.setText("no server");
        } else
        if (v.getId() == buttonPlayPause.getId())
        {

            try {
                clientSocket.musicPlayPause();
            } catch (Exception e) {
                Log.d("||||||||||||", "error play/pause");
                e.printStackTrace();
            }

        } else
        if (v.getId() == buttonLeft.getId())
        {
            try {
                clientSocket.musicRewindLeft();
            } catch (Exception e) {
                Log.d("||||||||||||", "error rewind left");
                e.printStackTrace();
            }
        } else
        if (v.getId() == buttonRight.getId())
        {
            try {
                clientSocket.musicRewindRight();
            } catch (Exception e) {
                Log.d("||||||||||||", "error rewind right");
                e.printStackTrace();
            }
        }
    }

    @Override
    public boolean dispatchKeyEvent(KeyEvent event)
    {
        int action = event.getAction();
        int keyCode = event.getKeyCode();
        switch (keyCode) {
            case KeyEvent.KEYCODE_VOLUME_UP:
                if (action == KeyEvent.ACTION_DOWN) {

                    try {
                        clientSocket.volumeUp();
                    } catch (Exception e) {
                        Log.d("|||||||||", "error volume up");
                        e.printStackTrace();
                    }
                    return true;
                }
                return true;
            case KeyEvent.KEYCODE_VOLUME_DOWN:
                if (action == KeyEvent.ACTION_DOWN) {
                    try {
                        clientSocket.volumeDown();
                    } catch (Exception e) {
                        Log.d("|||||||||", "error volume down");
                        e.printStackTrace();
                    }
                    return true;
                }
                return true;
            default:
                return super.dispatchKeyEvent(event);
        }
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data)
    {
        final Intent tempData = data;
        if (requestCode == MUSIC_PATH_CODE)
        {
            if (resultCode == RESULT_OK)
            {
                if (!clientSocket.isConneted())
                    return;
                new Thread()
                {
                    @Override
                    public void run()
                    {
                        try {
                            clientSocket.sendMusic(tempData.getStringExtra("music"));
                        } catch (Exception e) {
                            Log.d("|||||||||", "error send");
                            e.printStackTrace();
                        }//
                    }
                }.start();
            }
        }
    }
}


