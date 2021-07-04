package stack;
/*Examples: 

Input :  Prefix :  *+AB-CD
Output : Postfix : AB+CD-*
Explanation : Prefix to Infix :  (A+B) * (C-D)
              Infix to Postfix :  AB+CD-*

Input :  Prefix :  *-A/BC-/AKL
Output : Postfix : ABC/-AK/L-*
Explanation : Prefix to Infix :  (A-(B/C))*((A/K)-L)
              Infix to Postfix : ABC/-AK/L-*

*/


class b3{

    static String stack[]=new String[50];
    static int top=-1;

    static void push(String a){
        if(top==49){
            return;
        }
        stack[++top]=a;
    }

    static String pop(){
        if(top!=-1)
            return stack[top--];
        return "-99";
    }

    static boolean isoperator(char a){
        switch(a){
            case '+':
            case '^':
            case '%':
            case '-':
            case '/':
            case '*': return true;
            default : return false;
        }
    }

    static String PrefixToPostfix(String prefix){
        int len=prefix.length();
        String postfix="";
        for(int i=len-1;i>=0;i--){
            if(isoperator(prefix.charAt(i))==true){
                String op1=pop();
                String op2=pop();
                String temp=op1+op2+prefix.charAt(i);
                push(temp);
            }
            else{
                push(prefix.charAt(i)+"");
            }
        }
        postfix=pop();
        return postfix;
    }

    public static void main(String[] args) {
        String prefix="*-A/BC-/AKL";
        String postfix=PrefixToPostfix(prefix);
        System.out.println("postfix expression: "+postfix);
    }
}