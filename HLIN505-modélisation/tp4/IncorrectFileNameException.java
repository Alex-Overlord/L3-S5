package tp4;

public class IncorrectFileNameException extends Exception {
    String fileName;

    public IncorrectFileNameException(String fileName) {
	super(fileName);
	this.fileName = fileName;
    }

    public String getFileName() { return fileName; }
}
