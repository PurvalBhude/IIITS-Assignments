package pack;

public class timetaken extends time{
    int c;

    public timetaken(int a,int b,int c) {
        super(a,b);
        this.c = c;
    }

    public int sum(){
        return (c+ super.sum());
    }
    
}