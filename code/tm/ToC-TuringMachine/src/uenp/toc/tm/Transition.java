/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package uenp.toc.tm;

/**
 *
 * @author wellington
 */
public class Transition {
    private Integer from;
    private Integer to;
    private Character read;
    private Character write;
    private Direction direction;

    public Transition() {
    }

    public Transition(Integer from, Integer to, Character read, Character write, Direction direction) {
        this.from = from;
        this.to = to;
        this.read = read;
        this.write = write;
        this.direction = direction;
    }

    //<editor-fold defaultstate="collapsed" desc="properties">
    public Integer getFrom() {
        return from;
    }
    
    public void setFrom(Integer from) {
        this.from = from;
    }
    
    public Integer getTo() {
        return to;
    }
    
    public void setTo(Integer to) {
        this.to = to;
    }
    
    public Character getRead() {
        return read;
    }
    
    public void setRead(Character read) {
        this.read = read;
    }
    
    public Character getWrite() {
        return write;
    }
    
    public void setWrite(Character write) {
        this.write = write;
    }
    
    public Direction getDirection() {
        return direction;
    }
    
    public void setDirection(Direction direction) {
        this.direction = direction;
    }
    
    
//</editor-fold>

    @Override
    public String toString() {
        return String.format("%d,%d,%s,%s,%s", from, to, read, write, direction);
    }

    
}
