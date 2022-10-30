using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MoveTerrain : MonoBehaviour
{
    public float velocity = 2f;
    public bool stop = false;
    // Update is called once per frame
    void Update()
    {
        if (!stop)
        {
            transform.Translate(0, 0, -velocity * Time.deltaTime);
        }
    }
}
