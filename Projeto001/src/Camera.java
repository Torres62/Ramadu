import java.io.File;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;

public class Camera {

	private static final int SLEEP_TIME = 10000;
	
	private File file;
	private Future<File> future;
	
	public Camera() {
		start();
	}
	
	private void start() {
		file = new File("");
		
		ExecutorService pool = Executors.newCachedThreadPool();
		future = pool.submit(() -> {
			
			Thread.sleep(SLEEP_TIME);
			return file;
		});
	}
	
	public boolean requestStop() {
		return future.isDone();
	}
	
	public File save(int min) throws InterruptedException, ExecutionException {
		return future.get();
	}
	
}
