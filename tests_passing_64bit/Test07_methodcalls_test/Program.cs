using System;

namespace Test07 {

    public class Program {

        public static readonly string TESTCASE = "TESTCASE07 : ";

        private const string TEST_PASSED = "test_passed";
        private const string TEST_FAILED = "test_FAILED";

        static void Main(string[] args) {
            Console.WriteLine( TESTCASE + "test different method-call types." );

            int callCount = 0;

            TestClass.StaticMethod();
            callCount++;

            TestClass c = new TestClass();

            c.InstanceMethod();
            callCount++;

            c.AncestorMethod();
            callCount++;

            c.VirtualMethod();
            callCount++;

            c.AbstractMethod();
            callCount++;

            c.InterfaceMethod();
            callCount++;

            Console.WriteLine( TESTCASE + "final InterfaceProperty = " + c.InterfaceProperty );
            Console.WriteLine( TESTCASE + "final callCount = " + callCount );

            Console.WriteLine( TESTCASE + TEST_PASSED );
        }
    }

    public interface TestInterface {
        int InterfaceProperty { get; }
        void InterfaceMethod();
    }

    internal abstract class Ancestor {
        public void AncestorMethod() {
            Console.WriteLine( Program.TESTCASE + "at Ancestor.AncestorMethod() " );
        }
        public virtual void VirtualMethod() {
            Console.WriteLine( Program.TESTCASE + "at Ancestor.VirtualMethod() " );
        }
        public abstract void AbstractMethod();
    }

    internal class TestClass : Ancestor, TestInterface {

        public int InterfaceProperty { get; private set; }

        public TestClass() {
            InterfaceProperty = 100;
        }

        public void InstanceMethod() {
            Console.WriteLine( Program.TESTCASE + "at TestClass.InstanceMethod() " );
        }

        public static void StaticMethod() {
            Console.WriteLine( Program.TESTCASE + "at TestClass.StaticMethod() " );
        }

        public override void VirtualMethod() {
            Console.WriteLine( Program.TESTCASE + "at TestClass.VirtualMethod() " );
        }

        public override void AbstractMethod() {
            Console.WriteLine( Program.TESTCASE + "at TestClass.AbstractMethod() " );
        }

        public void InterfaceMethod() {
            Console.WriteLine( Program.TESTCASE + "at TestClass.InterfaceMethod(), prop = " + InterfaceProperty );
            InterfaceProperty = 500;
        }
    }

}

