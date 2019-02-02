package com.predator.explorer;

import android.app.Activity;
import android.content.Intent;
import android.graphics.drawable.Drawable;
import android.media.MediaPlayer;
import android.net.Uri;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.ImageButton;
import android.widget.ImageView;
import android.widget.SeekBar;
import android.widget.Toast;

import java.io.IOException;

public class MusicPlayerActivity extends Activity implements View.OnClickListener, SeekBar.OnSeekBarChangeListener{

    private SeekBar seekBarMusicProgress;
    private ImageButton buttonPlay;
    private ImageView imageNote;

    private MediaPlayer mediaPlayer;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_music_player);

        imageNote = (ImageView)findViewById(R.id.imageNote);
        imageNote.setImageResource(R.drawable.note);

        buttonPlay = (ImageButton)findViewById(R.id.buttonPlay);
        buttonPlay.setImageResource(R.drawable.pause);
        buttonPlay.setOnClickListener(this);

        Intent intent = getIntent();
        String musicPath = intent.getStringExtra("music");
        mediaPlayer = MediaPlayer.create(this, Uri.parse(musicPath));

        mediaPlayer.seekTo(0);
        mediaPlayer.setLooping(false);
        mediaPlayer.setVolume(100f, 100f);
        mediaPlayer.start();

        seekBarMusicProgress = (SeekBar)findViewById(R.id.seekBarMusicProgress);
        seekBarMusicProgress.setMax(mediaPlayer.getDuration());
        seekBarMusicProgress.setOnSeekBarChangeListener(this);

        Thread myThread = new Thread()
        {
            @Override
            public void run() {
                while(true)
                {
                    if (mediaPlayer.isPlaying())
                    {
                        seekBarMusicProgress.setProgress(mediaPlayer.getCurrentPosition());
                        try {
                            Thread.sleep(1000);
                        } catch (InterruptedException e) {
                            e.printStackTrace();
                        }
                    }
                }
            }
        };
        myThread.start();
    }

    @Override
    public void onClick(View v) {
        if (v.getId() == buttonPlay.getId())
        {
            if (mediaPlayer.isPlaying())
            {
                buttonPlay.setImageResource(R.drawable.play);
                mediaPlayer.pause();
            }
            else
            {
                buttonPlay.setImageResource(R.drawable.pause);
                mediaPlayer.start();
            }
        }
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        mediaPlayer.stop();
    }

    @Override
    public void onProgressChanged(SeekBar seekBar, int progress, boolean fromUser) {
        if (seekBar.getId() == seekBarMusicProgress.getId())
        {
            if (fromUser)
            {
                mediaPlayer.seekTo(progress);
                seekBarMusicProgress.setProgress(progress);
            }
        }
    }
    @Override
    public void onStartTrackingTouch(SeekBar seekBar) {}

    @Override
    public void onStopTrackingTouch(SeekBar seekBar) {}
}
