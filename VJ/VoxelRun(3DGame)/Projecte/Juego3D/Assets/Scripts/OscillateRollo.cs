using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class OscillateRollo : MonoBehaviour
{

    public float velocity = 3f;
    // Update is called once per frame
    void Update()
    {
        Vector3 y = new Vector3(0, 1, 0);
        transform.Rotate(y, velocity * Time.deltaTime);
    }
}
