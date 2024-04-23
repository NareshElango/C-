public class Passenger{
    static int id=1;
    String name;
    int age;
    String gender;
    String bp;
    int passengerid=id++;
    String alloted;
    int number;

    public Passenger(String name,int age,String gender,String bp){
        this.name=name;
        this.age=age;
        this.gender=gender;
        this.bp=bp;
        alloted="";
        number=-1;
    }
}