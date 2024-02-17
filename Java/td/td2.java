package td;

public class td2 {
    public static void petit(int t[],int taille) {
        int min=t[0], occurence=0,i;
        for (i = 0; i < taille; i++) {
            if (t[i]<min) {
               min=t[i];
            }
        }
        for (i = 0; i < taille; i++) {
            if (t[i]==min) {
                occurence++;  
                occurence++;
            }
        }
        System.out.println("Le minimum est "+min+" il se trouve "+occurence+" fois dans le tableau");
    }

    public static void pairs(int A[],int taille) {
        int occurence=0,i;
        System.out.println("Les nombre pairs du tableau sont: ");
        for (i = 0; i < taille; i++) {
            if (A[i]%2==0) {
                System.out.println(A[i]);
                occurence++;
            }
        }
        System.out.println("Le tabeau contient "+occurence+" nombre pairs");
    }
    public static void moysup(int A[], int taille) {
        int n=0, i, somme=0;
        float moy;
        for (i = 0; i < taille; i++) {
            somme=somme+A[i];
        }
        moy=(float)somme/taille;
        for ( i = 0; i < taille; i++) {
            if (moy<A[i])
                n=n+1;
        }
        System.out.println("La moyenne du tableau est "+moy+", il y'a "+n+" nombre superieur la moyenne");

    }
    
    public static void main(String[] args) {
        int t[]={7,8,4,9,4};
        petit(t,5);
        pairs(t, 5);
        moysup(t, 5);
    }
}

