import java.util.Scanner;
import java.util.concurrent.ExecutionException;

public class Main {

	public static void main(String[] args) {
		System.out.println("Bem vindo!");
		System.out.println("Iniciando gravação");
		
		Camera camera = new Camera();
		
		for (;;) {
			if (camera.requestStop()) {
				break;
			}
		}
		String input = null;
		Scanner scanner = new Scanner(System.in);
		do {
			if (input != null) {
				System.out.println("VALOR INVÁLIDO");
			}
			
			System.out.println("Digite o tempo para salvar os últimos X minutis: ");
			input = scanner.next();

		} while (!isValidInput(input));
		
		int minutos = new Integer(input);
		try {
			camera.save(minutos);
			System.out.println("Arquivo salvo com sucesso");
			
		} catch (InterruptedException | ExecutionException e) {
			System.out.println("Erro ao salvar arquivo");
		}
		
		scanner.close();
		System.exit(0);
	}
	
	private static boolean isValidInput(String value) {
		if (value.isEmpty()) {
			return false;
		}
		
		for (char ch : value.toCharArray()) {
			
			if (!Character.isDigit(ch)) {
				return false;
			}
		}
		
		return true;
	}
	
}
