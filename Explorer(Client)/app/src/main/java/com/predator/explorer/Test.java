package com.predator.explorer;

import android.os.AsyncTask;
import android.util.Log;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.net.Inet4Address;
import java.net.InetAddress;
import java.net.Socket;

/**
 * Created by Predator on 30.01.2019.
 */

public class Test extends AsyncTask<Void,Void,Void>
{

    @Override
    protected Void doInBackground(Void... params) {
        try
        {
            Log.d("||||||||||||||||||||","try1");
            Socket socket = new Socket("192.168.43.23", 32532);
            Log.d("||||||||||||||||||||","try2");

//            DataOutputStream outStream = new DataOutputStream(socket.getOutputStream());
//
//            byte[] outBuf = {0x41, 0x42, 0x43, 0x44, 0x46};
//            outStream.write(outBuf);
//            outStream.close();
//            socket.close();

        }
        catch (Exception e)
        {
            Log.d("||||||||||||||||||||","error");
        }
        return null;
    }
}