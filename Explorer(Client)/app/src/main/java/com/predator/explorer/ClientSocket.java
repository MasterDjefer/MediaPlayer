package com.predator.explorer;


import android.util.Log;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.net.Inet4Address;
import java.net.InetAddress;
import java.net.InetSocketAddress;
import java.net.NetworkInterface;
import java.net.Socket;
import java.net.SocketException;
import java.net.UnknownHostException;
import java.util.Enumeration;

public class ClientSocket
{
    private Socket socket;
    private boolean connected;
    private boolean running;
    private DataOutputStream outStream;

    public ClientSocket()
    {
        socket = null;
        connected = false;
        running = false;
    }

    public void closeConnection() throws Exception
    {
        if (connected)
        {
            connected = false;

            outStream.write("close".getBytes());

            socket.close();
            socket = null;
            outStream.close();
        }
    }

    public boolean isConneted()
    {
        return connected;
    }


    public String connect() throws Exception {

        String addr = "";
        Enumeration e = NetworkInterface.getNetworkInterfaces();
        while(e.hasMoreElements())
        {
            NetworkInterface n = (NetworkInterface) e.nextElement();
            Enumeration ee = n.getInetAddresses();
            while (ee.hasMoreElements())
            {
                InetAddress iA = (InetAddress) ee.nextElement();
                if (iA instanceof Inet4Address)
                {
                    addr = iA.getHostAddress();
                    if (addr.equals("127.0.0.1"))
                        continue;

//                    s += addr + "\n";

                    addr = addr.substring(0, addr.lastIndexOf(".") + 1);

                    for (int i = 2; i < 256; ++i)
                    {
                        String tempAddr = addr + i;

                        try
                        {
                            socket = new Socket();
                            socket.connect(new InetSocketAddress(tempAddr, 32532), 10);
                        }
                        catch (Exception exc)
                        {
                            Log.d("|||||||||", "error connect " + tempAddr);
//                            s += "error connect " + tempAddr + "\n";
                            continue;
                        }

                        connected = true;
                        outStream = new DataOutputStream(socket.getOutputStream());
                        return tempAddr;
                    }
                }
            }
        }
        return "no server";
    }

    public void sendMusic(String path) throws Exception {
        //read music file
        FileInputStream fin = new FileInputStream(path);
        DataInputStream din = new DataInputStream(fin);


        outStream.write("receiving".getBytes());

//        send music package by bytes
        byte b[] = new byte[100000];
        while (din.read(b) > 1)
        {
            outStream.write(b);
        }
        outStream.write("sent".getBytes());
        running = true;


        din.close();
        fin.close();
    }

    public void musicPlayPause() throws Exception {

        if (running)
        {
            outStream.write("pause".getBytes());
        }
        else
        {
            outStream.write("play".getBytes());
        }
        running = !running;
    }

    public void musicRewindLeft() throws Exception {

        if (socket != null)
        {
            outStream.write("left".getBytes());
        }
    }

    public void musicRewindRight() throws Exception {

        if (socket != null)
        {
            outStream.write("right".getBytes());
        }
    }

    public void volumeUp() throws Exception {

        if (socket != null)
        {
            outStream.write("volumeUp".getBytes());
        }
    }

    public void volumeDown() throws Exception {

        if (socket != null)
        {
            outStream.write("volumeDown".getBytes());
        }
    }
}
