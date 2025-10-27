/*
* File Name: ColouredFrameDecorator.java
* Assignment: Lab 6 -- The Decorator Pattern
* Lab section: B01
* Completed by: Al Malik Mahdivika
* Development Date: Oct 27, 2025
*/

import java.awt.BasicStroke;
import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Stroke;

public class ColouredFrameDecorator extends Decorator {
    protected int thickness;
    public ColouredFrameDecorator(Component cmp, int x, int y, int w, int h, int t) {
        this.cmp = cmp;
        this.x = x;
        this.y = y;
        this.width = w;
        this.height = h;
        this.thickness = t;
    }

    @Override
    public void draw(Graphics g) {
        cmp.draw(g);

        Graphics2D g2d = (Graphics2D) g;
        Stroke oldStroke = g2d.getStroke();
        Color oldColor = g2d.getColor();
        g2d.setStroke(new BasicStroke(this.thickness));
        g2d.setColor(Color.RED);
        g2d.drawRect(x, y, width, height);
        g2d.setStroke(oldStroke);
        g2d.setColor(oldColor);
    }
}
