import 'package:flutter/material.dart';

class TasksTile extends StatelessWidget {
  const TasksTile({super.key});

  @override
  Widget build(BuildContext context) {
    return const ListTile(
      title: Text('Task1 '),
      trailing: Checkbox(
        value: false,
        onChanged: null,
      ),
    );
  }
}
