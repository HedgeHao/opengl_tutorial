# Example0
* basics of C++
* build share library
```
gcc -g -fPIC -c -C foo.c
gcc -shared foo.o -o libfoo.so
```

## Flutter wrapper
* [flutter use C interface](https://stackoverflow.com/questions/61595179/can-i-call-a-c-constructor-function-in-dart-ffi)

```dart
import 'dart:ffi';

import 'package:ffi/ffi.dart';
import 'package:flutter/material.dart';

late DynamicLibrary lib;
typedef person_new = Pointer<Void> Function(Int32 age, Pointer<Utf8> name);
typedef NativePersonNewSymbol = Pointer<Void> Function(int age, Pointer<Utf8> name);
late NativePersonNewSymbol personNew;

typedef person_whoami = Pointer<Utf8> Function(Pointer<Void> ptr);
typedef NativePersonWhoamiSymbol = Pointer<Utf8> Function(Pointer<Void> ptr);
late NativePersonWhoamiSymbol personWhoami;

class Person {
  late Pointer<Void> instance;

  Person(int age, String name) {
    instance = personNew(age, name.toNativeUtf8());
  }

  String whoami() {
    return personWhoami(instance).toDartString();
  }
}

late Person p;
void main() {
  lib = DynamicLibrary.open('lib/library/libperson.so');
  personNew = lib.lookupFunction<person_new, NativePersonNewSymbol>('person_new');
  personWhoami = lib.lookupFunction<person_whoami, NativePersonWhoamiSymbol>('person_whoami');

  p = Person(11, 'Josh');

  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Flutter Demo',
      home: Scaffold(body: Text(p.whoami())),
    );
  }
}
```