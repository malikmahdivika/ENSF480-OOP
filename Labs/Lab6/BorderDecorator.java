/*
* File Name: BorderDecorator.java
* Assignment: Lab 6 -- The Decorator Pattern
* Lab section: B01
* Completed by: Al Malik Mahdivika
* Development Date: Oct 27, 2025
*/

import java.awt.BasicStroke;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Stroke;

public class BorderDecorator extends Decorator {
    public BorderDecorator(Component cmp, int x, int y, int w, int h) {
        this.cmp = cmp;
        this.x = x;
        this.y = y;
        this.width = w;
        this.height = h;
    }

    @Override
    public void draw(Graphics g) {
        cmp.draw(g);
        Graphics2D g2d = (Graphics2D) g;
        Stroke oldStroke = g2d.getStroke();
        g2d.setStroke(new BasicStroke(5, BasicStroke.CAP_BUTT, 
        BasicStroke.JOIN_BEVEL, 0, new float[]{9}, 0));
        g2d.drawRect(x, y, width, height);
        g2d.setStroke(oldStroke);
    }
}
