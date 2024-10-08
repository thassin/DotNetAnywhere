// Copyright (c) 2012 DotNetAnywhere
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#if !LOCALTEST

using System.Runtime.CompilerServices;

namespace System {

// in principle Object implements ICloneable but:
// ./System/Object.cs(27,15): error CS0537: The class System.Object cannot have a base class or implement an interface.
// => AND the Clone() method is internal.

// for some reason the mcs compiler has difficulty to handle object.Clone() but Object.Clone() works OK.

	public class Object {

		public Object() {
		}

		~Object() {
		}

		[MethodImpl(MethodImplOptions.InternalCall)]
		extern public Type GetType();

		[MethodImpl(MethodImplOptions.InternalCall)]
		extern public virtual bool Equals(object obj);

		[MethodImpl(MethodImplOptions.InternalCall)]
		extern public virtual int GetHashCode();

		public virtual string ToString() {
			return this.GetType().FullName;
		}

		public static bool Equals(object a, object b) {
			if (a == b) {
				return true;
			}
			if (a == null || b == null) {
				return false;
			}
			return a.Equals(b);
		}

		public static bool ReferenceEquals(object a, object b) {
			return (a == b);
		}

		[MethodImpl(MethodImplOptions.InternalCall)]
		extern internal static object Clone(object obj);
	}
}
#endif
