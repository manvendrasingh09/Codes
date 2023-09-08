import 'package:flutter/material.dart';
import 'constants.dart';

class BottomButton extends StatelessWidget {
  const BottomButton({super.key, required this.bText, required this.onTap});
  final String bText;
  final VoidCallback onTap;
  @override
  Widget build(BuildContext context) {
    return GestureDetector(
      onTap: onTap,
      child: Container(
        color: kBottomContainerColour,
        margin: const EdgeInsets.only(top: 10.0),
        padding: const EdgeInsets.only(bottom: 10.0),
        height: kBottomContainerHeight,
        width: double.infinity,
        child: Center(
          child: Text(
            bText,
            style: kLargeButton,
          ),
        ),
      ),
    );
  }
}
