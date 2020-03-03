clear
javac -cp /net/apps/eclipse-neon-java/eclipse/plugins/org.junit_4.12.0.v201504281640/junit.jar:/net/apps/eclipse-neon-java/eclipse/plugins/org.hamcrest.core_1.3.0.v201303031735.jar $1/*.java
java $1.Main
echo