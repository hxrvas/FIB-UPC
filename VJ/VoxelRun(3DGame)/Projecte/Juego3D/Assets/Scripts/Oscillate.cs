using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Oscillate : MonoBehaviour {

    public float velocity = 3f;
    // Update is called once per frame
    float time = 0;
    void Update()
    {
        time += Time.deltaTime;
        Vector3 z = new Vector3(0, 0, 1);
        transform.Rotate(z, velocity * Mathf.Sin(time) * Time.deltaTime);
    }
}
