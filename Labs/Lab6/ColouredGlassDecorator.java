/*
* File Name: ColouredGlassDecorator.java
* Assignment: Lab 6 -- The Decorator Pattern
* Lab section: B01
* Completed by: Al Malik Mahdivika
* Development Date: Oct 27, 2025
*/

import java.awt.AlphaComposite;
import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;

public class ColouredGlassDecorator extends Decorator {
    public ColouredGlassDecorator(Component cmp, int x, int y, int w, int h) {
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
        Color oldColor = g2d.getColor();
        g2d.setColor(Color.green);
        g2d.setComposite(AlphaComposite.getInstance(AlphaComposite.SRC_OVER, 0.1f * 1));
        g2d.fillRect(x, y, width, height);
    }
}
