package com.predator.explorer;

import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.drawable.Drawable;
import android.net.Uri;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.ImageView;
import android.widget.Toast;

import java.io.IOException;
import java.io.InputStream;
import java.net.URL;

public class ImageBrowserActivity extends AppCompatActivity {

    private ImageView imageWindow;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_image_browser);

        imageWindow = (ImageView)findViewById(R.id.imageWindow);

        String imagePath = getIntent().getStringExtra("image");
        try {
            imageWindow.setImageBitmap(getBitmap(imagePath));
        }
        catch (Exception e)
        {
            Toast.makeText(ImageBrowserActivity.this, "Error", Toast.LENGTH_SHORT).show();
            e.printStackTrace();
        }
    }

    private Bitmap getBitmap(String url)
    {
        return BitmapFactory.decodeFile(url);
    }
}
