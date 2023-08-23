import 'package:audioplayers/audioplayers.dart';
import 'package:flutter/material.dart';

void main() {
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  Expanded buildKey(Color color, int a) {
    return Expanded(
      child: MaterialButton(
        color: color,
        onPressed: () {
          final player = AudioPlayer();
          player.setSource(
            AssetSource('note$a.wav'),
          );
          player.resume();
        },
      ),
    );
  }

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      home: Scaffold(
        backgroundColor: Colors.black,
        body: SafeArea(
          child: Column(
            crossAxisAlignment: CrossAxisAlignment.stretch,
            children: [
              buildKey(Colors.red, 1),
              buildKey(Colors.blue, 2),
              buildKey(Colors.green, 3),
              buildKey(Colors.yellow, 4),
              buildKey(Colors.orange, 5),
              buildKey(Colors.purple, 6),
              buildKey(Colors.brown, 7),
            ],
          ),
        ),
      ),
    );
  }
}
