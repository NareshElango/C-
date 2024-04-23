import java.util.Scanner;

public class Sample{
    public static void bookticket(Passenger p){
        TicketBook tb=new TicketBook();
        if(TicketBook.awl==0){
        System.out.println("No tickets left");
        return;
        }
        if((p.bp.equals("L")&&TicketBook.alb>0)||(p.bp.equals("M")&&TicketBook.amb>0)||(p.bp.equals("U")&&TicketBook.aub>0)){
            if(p.bp.equals("L")){
                System.out.println("Lower berth given");
                tb.bookticket(p, (TicketBook.lbp.get(0)), "L");
                TicketBook.lbp.remove(0);
                TicketBook.alb--;
            }
            else if(p.bp.equals("M")){
                System.out.println("Middle berth given");
                tb.bookticket(p, (TicketBook.mbp.get(0)), "M");
                TicketBook.mbp.remove(0);
                TicketBook.amb--;
            }
            else if(p.bp.equals("U")){
                System.out.println("Upper berth given");
                tb.bookticket(p, (TicketBook.ubp.get(0)), "U");
                TicketBook.ubp.remove(0);
                TicketBook.aub--;
            }
        }else if(TicketBook.alb>0){
                System.out.println("Lower berth given");
                tb.bookticket(p, (TicketBook.lbp.get(0)), "L");
                TicketBook.lbp.remove(0);
                TicketBook.alb--;
            }
        else if(TicketBook.amb>0){
                System.out.println("Middle berth given");
                tb.bookticket(p, (TicketBook.mbp.get(0)), "M");
                TicketBook.mbp.remove(0);
                TicketBook.amb--;
            }
        else if(TicketBook.aub>0){
                System.out.println("Upper berth given");
                tb.bookticket(p, (TicketBook.ubp.get(0)), "U");
                TicketBook.ubp.remove(0);
                TicketBook.aub--;
            }
        else if(TicketBook.arac>0){
                System.out.print("RAC given");
                tb.racticket(p, (TicketBook.rac.get(0)), "RAC");
                TicketBook.rac.remove(0);
                TicketBook.arac--;
            }
        else if(TicketBook.awl>0){
                System.out.println("Wating list given");
                tb.wlticket(p, (TicketBook.wlp.get(0)), "WL");

                TicketBook.wlp.remove(0);
                TicketBook.awl--;
            }
    }

    public static void cancelticket(int id){
        TicketBook tb=new TicketBook();
                if(!tb.passenger_stored_data.containsKey(id)){
                    System.out.println("No such passenger found!");
                }
                else{
                    tb.cancelticket(id);
                }
            }
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        boolean loop=true;
        while(loop){
            System.out.println("1.book \n2.cancel \n3.available ticket \n4.booked tickets \n5.exit");
            int n;
            n =sc.nextInt();
            sc.nextLine();
            switch(n){
                case 1:{
                    System.err.println("Enter the passenger name:");
                    String name=sc.nextLine();
                    sc.nextLine();
                    System.err.println("enter the passenger age");
                    int age=sc.nextInt();
                    sc.nextLine();
                    System.err.println("enter the gender");
                    String gender=sc.nextLine();
                    sc.nextLine();
                    System.err.println("enter the berth preference");
                    String bp=sc.nextLine();
                    Passenger p=new Passenger(name,age,gender,bp);
                    bookticket(p);
                    break;

                }
                case 2:{
                    System.out.println("enter the passenger id");
                    int id;
                    id=sc.nextInt();
                    cancelticket(id);
                }
                case 3:{
                    TicketBook tb=new TicketBook();
                    tb.passengersdetails();
                    break;
                }
                case 5:{
                    loop = false;
                    break;
                }
            }
        }
    }
}

