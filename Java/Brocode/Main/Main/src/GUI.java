import javax.swing.JOptionPane;
public class GUI {
    public static void main(String[] args) {
        String name = JOptionPane.showInputDialog("Entrer votre nom:");
        JOptionPane.showMessageDialog(null, name);
    }
}
