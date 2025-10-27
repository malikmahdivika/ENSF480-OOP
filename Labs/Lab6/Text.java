/*
* File Name: Text.java
* Assignment: Lab 6 -- The Decorator Pattern
* Lab section: B01
* Completed by: Al Malik Mahdivika
* Development Date: Oct 27, 2025
*/

import java.awt.Graphics;

public class Text implements Component {
    protected int x;
    protected int y;
    protected String text;

    public Text(String text,int x, int y) {
        this.text = text;
        this.x = x;
        this.y = y;
    }

    @Override
    public void draw(Graphics g) {
        g.drawString(text, x, y);
    }
}
