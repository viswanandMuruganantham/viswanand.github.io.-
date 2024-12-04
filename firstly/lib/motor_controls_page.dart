import 'package:flutter/material.dart';

class MotorControlsPage extends StatelessWidget {
  const MotorControlsPage({super.key});

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text('Motor Controls'),
      ),
      body: Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: <Widget>[
            const Text(
              'Do you want to on the motor?',
              style: TextStyle(fontSize: 18),
            ),
            const SizedBox(height: 20), // Space between question and buttons
            Row(
              mainAxisAlignment: MainAxisAlignment.center,
              children: <Widget>[
                ElevatedButton(
                  onPressed: () {
                    // Handle Yes action
                    Navigator.pop(context);
                  },
                  child: const Text('Yes'),
                ),
                const SizedBox(width: 20), // Space between buttons
                ElevatedButton(
                  onPressed: () {
                    // Handle No action
                    Navigator.pop(context);
                  },
                  child: const Text('No'),
                ),
              ],
            ),
          ],
        ),
      ),
    );
  }
}
