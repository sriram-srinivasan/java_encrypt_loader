package net.malhar;
import java.lang.reflect.*;

public class Main {
    public static void main(String[] args) throws Exception {
        System.out.println("Loading Precious");
        loadClasses();
        Class<?> cl = Class.forName("net.malhar.Precious");
        Method method = cl.getMethod("sayHello");
        method.invoke(null); // static method
    }

    // loadClasses is defined in the agent itself; see agent_src/agent.cpp
    static native void loadClasses();
}